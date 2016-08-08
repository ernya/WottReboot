#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Rotation.hpp"

#include <iostream>

I3DObject &Rotation::applyMatrix(const I3DMatrix &matrix) 
{
	_matrix = matrix.getMatrix() * _matrix;
	return *this;
};

I3DObject &Rotation::applyLocalMatrix(const I3DMatrix &matrix) 
{
	return applyMatrix(matrix);
};

const glm::mat4 &Rotation::getMatrix() const 
{
	return _matrix;
}

Rotation::Rotation(float x, float y, float z) : _x(x), _y(y), _z(z)
{
	refreshMatrix();
}

void Rotation::refreshMatrix()
{
	_matrix = glm::mat4(1.0f);
	glm::mat4 matrixx = glm::rotate(_matrix, _x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 matrixy = glm::rotate(_matrix, _y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 matrixz = glm::rotate(_matrix, _z, glm::vec3(0.0f, 0.0f, 1.0f));
	_matrix = matrixx * _matrix;
	_matrix = matrixy * _matrix;
	_matrix = matrixz * _matrix;
}

void Rotation::setX(float x)
{
	_x = x;
	refreshMatrix();
}

void Rotation::setY(float y)
{
	_y = y;
	refreshMatrix();
}

void Rotation::setZ(float z)
{
	_z = z;
	refreshMatrix();
}

void Rotation::add(float x, float y, float z)
{
	_x += x;
	_y += y;
	_z += z;
	refreshMatrix();
}

void Rotation::add(const glm::vec3 &vec)
{
	add(vec.x, vec.y, vec.z);
}

Rotation &Rotation::operator+(const glm::vec3 &vec)
{
	add(vec.x, vec.y, vec.z);
	return *this;
}