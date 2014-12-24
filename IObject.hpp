#pragma once

class Window;

class IObject
{
	virtual void internal_init(Window *win) = 0;
public: 
	virtual ~IObject() {};
	friend class Window;
};
