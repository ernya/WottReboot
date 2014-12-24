#include <iostream>
#include "Window.hpp"
#include "Triangle.hpp"
#include "Cube.hpp"
#include "Camera.hpp"
#include "Logging.hpp"

int	main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
	Window _win;
	try
	{
		VideoFlags &flags = _win.getVideoFlags();
		flags.setTitle("Wott Reboot");
		flags.setFSAASamples(VideoFlags::FSAA_2X);
		flags.setRefreshRate(VideoFlags::DEFAULT_REFRESH_RATE);
		flags.setResizable(true);
		VideoMode toto(&_win);
		toto.setHeight(768);
		toto.setWidth(1024);
		toto.createWindow();
		Camera *cam = new Camera(0, 0, -1.0f);
		cam->lookAt(glm::vec3(0, 0, 0));
		_win.addCamera(cam);
		Cube *cube = new Cube(0,0,0);
		_win.addObject(cube);
		_win.setClearColor(Color(0, 0, 0.4f, 1.0f));
		_win.run();
	}
	catch (std::runtime_error e)
	{
		Logging::fatal(e.what());
		Logging::end();
		int null;
		std::cin >> null;
		return EXIT_FAILURE;
	}
	Logging::info("Program Exited Successfully");
	Logging::end();
	return EXIT_SUCCESS;
}
