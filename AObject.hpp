#pragma once

#include <list>
#include "IObject.hpp"
#include "I3DObject.hpp"
#include "Translation.hpp"
#include "Scale.hpp"
#include "Rotation.hpp"
#include "GeometryHandler.hpp"

class ADrawable;
class IUpdatable;

class AObject : public IObject, public I3DObject
{
private:
	Translation _translation;
	Scale _scale;
	Rotation _rotation;
	AObject *_parent;
protected:
	std::list<ADrawable *> _subdrawables;
	std::list<IUpdatable *> _subupdatables;
	GeometryHandler _geometry;
	void translate(glm::vec3 vector);
	void translate(float x, float y, float z);
	void setTranslation(glm::vec3 vector);
	void setTranslation(float x, float y, float z);
	void rotate(glm::vec3 vector);
	void rotate(float x, float y, float z);
	void setRotation(glm::vec3 vector);
	void setRotation(float x, float y, float z);
	void scale(float x, float y, float z);
	void scale(glm::vec3 vector);
	void setScale(glm::vec3 vector);
	void setScale(float x, float y, float z);
	void applyTransformations()
	{
		_geometry.generateVBD();
		if (_parent)
		{
			applyMatrix(_parent->_scale);
			applyMatrix(_scale);
			applyMatrix(_parent->_rotation);
			applyMatrix(_rotation);
			applyMatrix(_parent->_translation);
			applyMatrix(_translation);
		}
		else
		{
			applyMatrix(_scale);
			applyMatrix(_rotation);
			applyMatrix(_translation);
		}
	}
public:
	AObject() : _parent(NULL) {}
	void addSubObject(AObject *obj, Window *win);
};