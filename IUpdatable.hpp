#pragma once

#include "AObject.hpp"

class IUpdatable : public virtual AObject
{
public :
	virtual void update() = 0;
	virtual ~IUpdatable() {};
};
