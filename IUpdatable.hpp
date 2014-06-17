#pragma once

#include "AObject.hpp"

class AObject;

class IUpdatable : public virtual AObject
{
	void internal_update()
	{
		update();
		for (std::list<IUpdatable *>::iterator it = _subupdatables.begin(); it != _subupdatables.end(); ++it)
		{
			(*it)->internal_update();
		}
	}
public :
	virtual void update() = 0;
	virtual ~IUpdatable() {};
	friend Window;
};
