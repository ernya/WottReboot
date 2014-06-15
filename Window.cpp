#include "Window.hpp"

Window::Window(void) : _modes(), _desktopMode(VideoMode(this)), _input(), _window(NULL)
{
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
	drawable->load();
	_drawableObjects.push_back(drawable);
}

void Window::addUpdatable(IUpdatable *updatable)
{
	_updatableObjects.push_back(updatable);
}

void Window::addObject(IObject *object)
{
	ADrawable *drawable = dynamic_cast<ADrawable *>(object);
	IUpdatable *updatable = dynamic_cast<IUpdatable *>(object);
	object->init(this);
	if (drawable)
		addDrawable(drawable);
	if (updatable)
		addUpdatable(updatable);
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
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, _flags.isResizable());
	glfwWindowHint(GLFW_REFRESH_RATE, _flags.getRefreshRate());
	if (!(_window = glfwCreateWindow(width, height, _flags.getTitle().c_str(), isFullScreen ? glfwGetPrimaryMonitor() : NULL, NULL)))
	{
		glfwTerminate();
		throw std::runtime_error("Could not open window (glfwOpenWindow() returned 0) ! Exiting...");
	}
	glfwMakeContextCurrent(_window);
	_input.init(_window);
	int ret = glewInit();
	if (ret != GLEW_OK)
		throw std::runtime_error("Could not initalize GLEW (glewInit() did not return GLEW_OK) ! Exiting...");	
}

void Window::run()
{
	do 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (std::list<IUpdatable *>::iterator it = _updatableObjects.begin() ; it != _updatableObjects.end() ; ++it)
			(*it)->update();
		for (std::list<ADrawable *>::iterator it = _drawableObjects.begin() ; it != _drawableObjects.end() ; ++it)
			(*it)->internal_draw();
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}
	while (!_input.isPressed(GLFW_KEY_ESCAPE));
}

void Window::setClearColor(Color color) const
{
	glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}

Window::~Window(void)
{
	for (std::list<ADrawable *>::iterator it = _drawableObjects.begin() ; it != _drawableObjects.end() ; ++it)
	{
		(*it)->unload();
		delete (*it);
	}
	glfwTerminate();
}
