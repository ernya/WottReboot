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
class AUpdatable;

class AObject : public IObject, public I3DObject
{
private:
	Translation _translation;
	Scale _scale;
	Rotation _rotation;
	AObject *_parent;

	bool		_positionNeedsUpdating;
protected:
	std::list<ADrawable *> _subdrawables;
	std::list<AUpdatable *> _subupdatables;
	Camera *_camera;
	GeometryHandler _geometry;
	glm::vec3	_worldPosition;
	glm::mat4	_localPositionMatrix;
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
    void internal_init(Window *win);

	void applyTransformations(const glm::vec3 &parentPosition);
public:
	AObject() : _parent(NULL) {}
	void addSubObject(AObject *obj, Window *win);
	virtual void init(Window *win) = 0;
};
