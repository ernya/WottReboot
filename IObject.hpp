#pragma once

class Window;

class IObject
{
public: 
	virtual void init(Window *win) = 0;
	virtual ~IObject() {};
};
