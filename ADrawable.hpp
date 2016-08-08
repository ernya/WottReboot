#pragma once

#include "AObject.hpp"
#include "Window.hpp"

class Window;
class AObject;

class ADrawable : public virtual AObject
{
	void internal_draw(const glm::vec3 &parentPosition, const glm::mat4 &vpMatrix) 
	{
		_geometry.generateVBD();
		applyTransformations(parentPosition);

		glm::mat4 newmatrix = vpMatrix * _localPositionMatrix;
		if (_isLoaded)
			draw(newmatrix);
		for (std::list<ADrawable *>::iterator it = _subdrawables.begin(); it != _subdrawables.end(); ++it)
		{
			(*it)->internal_draw(_worldPosition, newmatrix);
		}
	}

	void internal_load()
	{
		load();
	}

	void internal_unload()
	{
		for (std::list<ADrawable *>::iterator it = _subdrawables.begin(); it != _subdrawables.end(); ++it)
		{
			(*it)->internal_unload();
		}
		unload();
	}

protected:
	bool _isLoaded;
public:
	ADrawable() : _isLoaded(false) {}
	virtual void load() = 0;
	virtual void draw(const glm::mat4 &viewProjectionMatrix) = 0;
	virtual void unload() = 0;
	virtual ~ADrawable() {};
	friend class Window;
};
