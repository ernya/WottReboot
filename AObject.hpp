#pragma once

#include <list>
#include "IObject.hpp"
#include "I3DObject.hpp"
#include "TransformationMatrix.hpp"
#include "Translation.hpp"
#include "Scale.hpp"
#include "Rotation.hpp"
#include "GeometryHandler.hpp"
#include "Camera.hpp"

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
  Camera *_camera;
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
		glm::mat4 tfMatrix(1.0);
		if (_parent)
		{
			_aggregatescale.applyMatrix(_parent->_aggregatescale);
			_aggregatescale.applyMatrix(_scale);
			tfMatrix = _aggregatescale.getMatrix() * tfMatrix;
			_aggregaterotation.applyMatrix(_parent->_aggregaterotation);
			_aggregaterotation.applyMatrix(_rotation);
			tfMatrix = _aggregaterotation.getMatrix() * tfMatrix;
			_aggregatetranslation.applyMatrix(_parent->_aggregatetranslation);
			_aggregatetranslation.applyMatrix(_translation);
			tfMatrix = _aggregatetranslation.getMatrix() * tfMatrix;
			applyMatrix(TransformationMatrix(tfMatrix));
		}
		else
		{
			_aggregatescale = _scale;
			tfMatrix = _scale.getMatrix() * tfMatrix;
			_aggregaterotation = _rotation;
			tfMatrix = _rotation.getMatrix() * tfMatrix;
			_aggregatetranslation = _translation;
			tfMatrix = _translation.getMatrix() * tfMatrix;
			applyMatrix(TransformationMatrix(tfMatrix));
		}
	}

  void internal_init(Window *win);
public:
	AObject() : _parent(NULL) {}
	void addSubObject(AObject *obj, Window *win);
	virtual void init(Window *win) = 0;
};
