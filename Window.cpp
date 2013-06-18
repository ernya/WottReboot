#include "Window.hpp"

Window::Window(void) : _modes(VIDEO_MODES_LIMIT, VideoMode(this)), _desktopMode(VideoMode(this)), _input()
{
	if (!glfwInit())
		throw std::runtime_error("Could not initialize GLFW (glfwInit() returned 0) ! Exiting...");
	glewExperimental = true;
	GLFWvidmode *vidmode = new GLFWvidmode[VIDEO_MODES_LIMIT];
	int nb_modes = glfwGetVideoModes(vidmode, VIDEO_MODES_LIMIT);
	_modes.resize(nb_modes, VideoMode(this));
	for (int i = 0 ; i < nb_modes ; ++i)
	{
		_modes[i].setHeight(vidmode[i].Height);
		_modes[i].setWidth(vidmode[i].Width);
		_modes[i].setBpp(vidmode[i].RedBits + vidmode[i].BlueBits + vidmode[i].GreenBits);
	}
	delete [](vidmode);
	GLFWvidmode *desktopmode = new GLFWvidmode();
	glfwGetDesktopMode(desktopmode);
	_desktopMode.setWidth(desktopmode->Width);
	_desktopMode.setHeight(desktopmode->Height);
	_desktopMode.setBpp(desktopmode->BlueBits + desktopmode->RedBits + desktopmode->GreenBits);
	delete (desktopmode);
}

void Window::addDrawable(IDrawable *drawable)
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
	IDrawable *drawable = dynamic_cast<IDrawable *>(object);
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

void Window::openWindow(int width, int height, int bpp, bool isFullScreen) const
{
	if (width == -1 && height == -1 && bpp == -1)
	{
		const VideoMode current = getDesktopVideoMode();
		current.createWindow();
		return ;
	}
	_input.init();
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, _flags.getFSAASamples());
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, OPENGL_VERSION_MINOR);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, !_flags.isResizable());
	glfwOpenWindowHint(GLFW_REFRESH_RATE, _flags.getRefreshRate());
	if (!glfwOpenWindow(width, height, 0, 0, 0, 0, bpp, 0, isFullScreen ? GLFW_FULLSCREEN : GLFW_WINDOW))
	{
		glfwTerminate();
		throw std::runtime_error("Could not open window (glfwOpenWindow() returned 0) ! Exiting...");
	}

	glfwSetWindowTitle(_flags.getTitle().c_str());
	if (glewInit() != GLEW_OK)
		throw std::runtime_error("Could not initalize GLEW (glewInit() did not return GLEW_OK) ! Exiting...");	
}

void Window::run()
{
	do 
	{
		for (std::list<IUpdatable *>::iterator it = _updatableObjects.begin() ; it != _updatableObjects.end() ; ++it)
			(*it)->update();
		for (std::list<IDrawable *>::iterator it = _drawableObjects.begin() ; it != _drawableObjects.end() ; ++it)
			(*it)->draw();
		glfwSwapBuffers();
	}
	while (!_input.isPressed(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED));
}

Window::~Window(void)
{
	for (std::list<IDrawable *>::iterator it = _drawableObjects.begin() ; it != _drawableObjects.end() ; ++it)
	{
		(*it)->unload();
		delete (*it);
	}
	glfwTerminate();
}
