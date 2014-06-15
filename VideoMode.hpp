#pragma once

#include <iostream>
#include <stdexcept>

class Window;

class VideoMode
{
private:
	Window *_winptr;
protected:
	int _width;
	int _height;
public:
	VideoMode() {throw std::runtime_error("Tried to construct VideoMode with default constructor");}
	VideoMode(Window *_win): _winptr(_win) {}
	int getWidth() const {return (_width);}
	int getHeight() const {return (_height);}
	void setHeight(int h) {_height = h;}
	void setWidth(int w) {_width = w;}
	void createWindow(bool fullScreen = false) const;
	virtual ~VideoMode() {};
};
