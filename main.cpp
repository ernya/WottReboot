#include <iostream>
#include "Window.hpp"
#include "Triangle.hpp"
#include "Logging.hpp"

int	main(int argc, char **argv)
{
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
		Triangle *tri = new Triangle(-0.75, 0, 0);
		Triangle *tri2 = new Triangle(0, 0, 0);
		_win.addObject(tri);
		tri->addSubObject(tri2, &_win);
		tri2->addSubObject(new Triangle(0, 0, 0), &_win);
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
