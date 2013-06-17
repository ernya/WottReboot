#pragma once

#include <iostream>

class Window;

class VideoMode
{
private:
	const Window *_winptr;
protected:
	int _width;
	int _height;
	int _bpp;
public:
	VideoMode() {throw std::runtime_error("Tried to construct VideoMode with default constructor");}
	VideoMode(Window *_win): _winptr(_win) {}
	int getWidth() const {return (_width);}
	int getHeight() const {return (_height);}
	int getBpp() const {return (_bpp);}
	void setHeight(int h) {_height = h;}
	void setWidth(int w) {_width = w;}
	void setBpp(int bpp) {_bpp = bpp;}
	void createWindow(bool fullScreen = false) const;
	virtual ~VideoMode() {};
};
