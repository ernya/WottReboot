#pragma once

#include "IObject.hpp"

class IUpdatable : public virtual IObject
{
public :
	virtual void update() = 0;
	virtual ~IUpdatable() {};
};
