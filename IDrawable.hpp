#pragma once

#include "IObject.hpp"

class IDrawable : public virtual IObject
{
public:
	virtual void load() = 0;
	virtual void draw() = 0;
	virtual void unload() = 0;
	virtual ~IDrawable() {};
};
