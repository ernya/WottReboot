#include "ADrawable.hpp"
#include "IUpdatable.hpp"
#include "AObject.hpp"

void AObject::internal_init(Window *win)
{
  _camera = win->getMainCamera();
  init(win);
}

void AObject::addSubObject(AObject *obj, Window *win)
{
	ADrawable *drawable = dynamic_cast<ADrawable *>(obj);
	AUpdatable *updatable = dynamic_cast<AUpdatable *>(obj);

	obj->_parent = this;
	obj->init(win);
	if (drawable)
	{
		_subdrawables.push_back(drawable);
		drawable->load();
	}
	if (updatable)
		_subupdatables.push_back(updatable);
	
}

void AObject::translate(glm::vec3 vector)
{
	_translation.add(vector);
	_positionNeedsUpdating = true;
}

void AObject::translate(float x, float y, float z)
{
	_translation.add(x, y, z);
	_positionNeedsUpdating = true;
}

void AObject::setTranslation(glm::vec3 vector)
{
	_translation.setX(vector.x);
	_translation.setY(vector.y);
	_translation.setZ(vector.z);
	_positionNeedsUpdating = true;
}

void AObject::setTranslation(float x, float y, float z)
{
	_translation.setX(x);
	_translation.setY(y);
	_translation.setZ(z);
	_positionNeedsUpdating = true;
}

void AObject::rotate(glm::vec3 vector)
{
	_rotation.add(vector);
	_positionNeedsUpdating = true;
}

void AObject::rotate(float x, float y, float z)
{
	_rotation.add(x, y, z);
	_positionNeedsUpdating = true;
}

void AObject::setRotation(glm::vec3 vector)
{
	_rotation.setX(vector.x);
	_rotation.setY(vector.y);
	_rotation.setZ(vector.z);
	_positionNeedsUpdating = true;
}

void AObject::setRotation(float x, float y, float z)
{
	_rotation.setX(x);
	_rotation.setY(y);
	_rotation.setZ(z);
	_positionNeedsUpdating = true;
}

void AObject::scale(float x, float y, float z)
{
	_scale.add(x, y, z);
	_positionNeedsUpdating = true;
}

void AObject::scale(glm::vec3 vector)
{
	_scale.add(vector);
	_positionNeedsUpdating = true;
}

void AObject::setScale(glm::vec3 vector)
{
	_scale.setX(vector.x);
	_scale.setY(vector.y);
	_scale.setZ(vector.z);
	_positionNeedsUpdating = true;
}

void AObject::setScale(float x, float y, float z)
{
	_scale.setX(x);
	_scale.setY(y);
	_scale.setZ(z);
	_positionNeedsUpdating = true;
}

void AObject::applyTransformations(const glm::vec3 &parentPosition)
{
	_worldPosition = parentPosition + _translation.getVector();

	if (_positionNeedsUpdating)
	{
		_localPositionMatrix = _translation.getMatrix() * _rotation.getMatrix() * _scale.getMatrix();
		_positionNeedsUpdating = false;
	}
}