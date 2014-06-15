#include "VideoMode.hpp"
#include "Window.hpp"

void VideoMode::createWindow(bool fullScreen) const
{
	_winptr->openWindow(_width, _height, fullScreen);
}