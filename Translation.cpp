#include "Translation.hpp"

I3DObject &Translation::applyMatrix(const I3DMatrix &matrix) 
{
	_matrix = matrix.getMatrix() * _matrix;
	return *this;
};

I3DObject &Translation::applyLocalMatrix(const I3DMatrix &matrix) 
{
	return applyMatrix(matrix);
}

const glm::mat4 &Translation::getMatrix() const 
{
	return _matrix;
}

Translation::Translation(float x, float y, float z) 
{
	_matrix[0][0] = 1;
	_matrix[1][1] = 1;
	_matrix[2][2] = 1;
	_matrix[3][3] = 1;
	_matrix[3][0] = x;
	_matrix[3][1] = y;
	_matrix[3][2] = z;
}

void Translation::add(float x, float y, float z)
{
	_matrix[3][0] += x;
	_matrix[3][1] += y;
	_matrix[3][2] += z;
}

void Translation::add(const glm::vec3 &vec)
{
	add(vec.x, vec.y, vec.z);
}

Translation &Translation::operator+(const glm::vec3 &vec)
{
	add(vec.x, vec.y, vec.z);
	return *this;
}