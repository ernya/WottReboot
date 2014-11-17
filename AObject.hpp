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
	Translation _aggregatetranslation;
	Scale _aggregatescale;
	Rotation _aggregaterotation;
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
		_aggregatetranslation.setX(0);
		_aggregatetranslation.setY(0);
		_aggregatetranslation.setZ(0);
		_aggregaterotation.setX(0);
		_aggregaterotation.setY(0);
		_aggregaterotation.setZ(0);
		_aggregatescale.setX(1);
		_aggregatescale.setY(1);
		_aggregatescale.setZ(1);
		_geometry.generateVBD();
		if (_parent)
		{
			_aggregatescale.applyMatrix(_parent->_aggregatescale);
			_aggregatescale.applyMatrix(_scale);
			applyMatrix(_aggregatescale);
			_aggregaterotation.applyMatrix(_parent->_aggregaterotation);
			_aggregaterotation.applyMatrix(_rotation);
			applyMatrix(_aggregaterotation);
			_aggregatetranslation.applyMatrix(_parent->_aggregatetranslation);
			_aggregatetranslation.applyMatrix(_translation);
			applyMatrix(_aggregatetranslation);
		}
		else
		{
			_aggregatescale = _scale;
			applyMatrix(_scale);
			_aggregaterotation = _rotation;
			applyMatrix(_rotation);
			_aggregatetranslation = _translation;
			applyMatrix(_translation);
		}
	}
public:
	AObject() : _parent(NULL) {}
	void addSubObject(AObject *obj, Window *win);
};