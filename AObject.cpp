#include "AObject.hpp"

void AObject::translate(glm::vec3 vector)
{
	_translation.add(vector);
}

void AObject::translate(float x, float y, float z)
{
	_translation.add(x, y, z);
}

void AObject::setTranslation(glm::vec3 vector)
{
	_translation.setX(vector.x);
	_translation.setY(vector.y);
	_translation.setZ(vector.z);
}

void AObject::setTranslation(float x, float y, float z)
{
	_translation.setX(x);
	_translation.setY(y);
	_translation.setZ(z);
}

void AObject::rotate(glm::vec3 vector)
{
	_rotation.add(vector);
}

void AObject::rotate(float x, float y, float z)
{
	_rotation.add(x, y, z);
}

void AObject::setRotation(glm::vec3 vector)
{
	_rotation.setX(vector.x);
	_rotation.setY(vector.y);
	_rotation.setZ(vector.z);
}

void AObject::setRotation(float x, float y, float z)
{
	_rotation.setX(x);
	_rotation.setY(y);
	_rotation.setZ(z);
}

void AObject::scale(float x, float y, float z)
{
	_scale.add(x, y, z);
}

void AObject::scale(glm::vec3 vector)
{
	_scale.add(vector);
}

void AObject::setScale(glm::vec3 vector)
{
	_scale.setX(vector.x);
	_scale.setY(vector.y);
	_scale.setZ(vector.z);
}

void AObject::setScale(float x, float y, float z)
{
	_scale.setX(x);
	_scale.setY(y);
	_scale.setZ(z);
}