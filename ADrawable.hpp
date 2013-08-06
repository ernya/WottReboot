#pragma once

#include "AObject.hpp"
#include "Window.hpp"

class Window;

class ADrawable : public virtual AObject
{
	void internal_draw() 
	{
		applyTransformations();
		draw();
	}
public:
	virtual void load() = 0;
	virtual void draw() = 0;
	virtual void unload() = 0;
	virtual ~ADrawable() {};
	friend class Window;
};
