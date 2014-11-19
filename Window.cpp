#include "Window.hpp"
#include "Logging.hpp"

#ifdef _WIN32
#include "WinThread.hpp" 
#include "WinMutex.hpp" 
#else
#include "UnixThread.hpp"
#include "UnixMutex.hpp"
#endif

Window::Window(void) : _modes(), _desktopMode(VideoMode(this)), _input(), _window(NULL)
{
#ifdef _WIN32
	_mutex = new WinMutex();
	_mutexLoading = new WinMutex();
#else
	_mutex = new UnixMutex();
	_mutexLoading = new UnixMutex();
#endif
	if (!glfwInit())
		throw std::runtime_error("Could not initialize GLFW (glfwInit() returned 0) ! Exiting...");
	glewExperimental = true;
	int nb_modes;
	const GLFWvidmode *vidmode = glfwGetVideoModes(glfwGetPrimaryMonitor(), &nb_modes);
	_modes.resize(nb_modes, VideoMode(this));
	for (int i = 0 ; i < nb_modes ; ++i)
	{
		_modes[i].setHeight(vidmode[i].height);
		_modes[i].setWidth(vidmode[i].width);
	}
	const GLFWvidmode *desktopmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	_desktopMode.setWidth(desktopmode->width);
	_desktopMode.setHeight(desktopmode->height);
}

void Window::addDrawable(ADrawable *drawable)
{
	drawable->internal_load();
	_drawableObjects.push_back(drawable);
}

void Window::addUpdatable(IUpdatable *updatable)
{
	_updatableObjects.push_back(updatable);
}

static int addObjectInternal(std::pair<Window &, IObject *> *_arg)
{
	_arg->first.addObjectBlocking(_arg->second);
	delete _arg;
	return EXIT_SUCCESS;
}

void Window::addObject(IObject *object)
{
	object->init(this);
	std::pair<Window &, IObject *> *pair = new std::pair<Window &, IObject *>(*this, object);
#ifdef _WIN32
	WinThread<std::pair<Window &, IObject *>*> *tmp = new WinThread<std::pair<Window &, IObject *>*>();
#else
	UnixThread<std::pair<Window &, IObject *>*> *tmp = new UnixThread<std::pair<Window &, IObject *>*>();
#endif	
	tmp->run(addObjectInternal, pair);
	_loadingThreads.push_back(tmp);
	
}

void Window::addObjectBlocking(IObject *object)
{
	ADrawable *drawable = dynamic_cast<ADrawable *>(object);
	IUpdatable *updatable = dynamic_cast<IUpdatable *>(object);
	_mutex->lock();
	if (drawable)
		addDrawable(drawable);
	if (updatable)
		addUpdatable(updatable);
	_mutex->unlock();
}

const VideoMode &Window::getBestVideoMode() const
{
	return (_modes.back());
}

const VideoMode &Window::getDesktopVideoMode() const
{
	return (_desktopMode);
}

const std::vector<VideoMode> &Window::getVideoModes() const
{
	return (_modes);
}

void Window::openWindow(int width, int height, bool isFullScreen)
{
	if (width == -1 && height == -1)
	{
		const VideoMode current = getDesktopVideoMode();
		current.createWindow();
		return ;
	}
	glfwWindowHint(GLFW_SAMPLES, _flags.getFSAASamples());
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Mac OS X Fix
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, _flags.isResizable());
	glfwWindowHint(GLFW_REFRESH_RATE, _flags.getRefreshRate());
	if (!(_window = glfwCreateWindow(width, height, _flags.getTitle().c_str(), isFullScreen ? glfwGetPrimaryMonitor() : NULL, NULL)))
	{
		glfwTerminate();
		throw std::runtime_error("Could not open window (glfwCreateWindow() returned 0) ! Exiting...");
	}
	glfwMakeContextCurrent(_window);
	_input.init(_window);
	int ret = glewInit();
	if (ret != GLEW_OK)
		throw std::runtime_error("Could not initalize GLEW (glewInit() did not return GLEW_OK) ! Exiting...");	
	glEnable (GL_DEPTH_TEST);
}

void Window::run()
{
	do 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_mutex->lock();
		for (std::list<IUpdatable *>::iterator it = _updatableObjects.begin() ; it != _updatableObjects.end() ; ++it)
			(*it)->internal_update();
		for (std::list<ADrawable *>::iterator it = _drawableObjects.begin() ; it != _drawableObjects.end() ; ++it)
			(*it)->internal_draw();
		_mutex->unlock();
		glfwPollEvents();
		glfwSwapBuffers(_window);
		_mutexLoading->lock();
		for (std::list<std::pair<void (*)(void *), void*> >::iterator it = _pendingRenderingActions[ExecutionPriority::HIGHEST].begin() ; it != _pendingRenderingActions[ExecutionPriority::HIGHEST].end() ;)
		{
			(*it).first((*it).second);
			std::list<std::pair<void (*)(void *), void*> >::iterator ittmp = it++;
			_pendingRenderingActions[ExecutionPriority::HIGHEST].erase(ittmp);
		}
		_mutexLoading->unlock();
	}
	while (!_input.isPressed(GLFW_KEY_ESCAPE));
}

void Window::setClearColor(Color color) const
{
	glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}

Window::~Window(void)
{
	for (std::list<IThread<std::pair<Window &, IObject *> *> *>::iterator it = _loadingThreads.begin() ; it != _loadingThreads.end() ; ++it)
	{
		(*it)->cancel();
		delete (*it);
	}
	for (std::list<ADrawable *>::iterator it = _drawableObjects.begin() ; it != _drawableObjects.end() ; ++it)
	{
		(*it)->internal_unload();
		delete (*it);
	}
	delete _mutexLoading;
	delete _mutex;
	glfwTerminate();
}
