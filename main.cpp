#include <iostream>
#include "Window.hpp"
#include "Triangle.hpp"

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
		_win.getDesktopVideoMode().createWindow();
		_win.addObject(new Triangle());
		_win.run();
	}
	catch (std::runtime_error e)
	{
		std::cerr << e.what() << std::endl;
		int null;
		std::cin >> null;
		return EXIT_FAILURE;
	}
	std::cout << "Program Exited Successfully" << std::endl;
	return EXIT_SUCCESS;
}
