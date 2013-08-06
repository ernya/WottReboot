#include "Scale.hpp"

I3DObject &Scale::applyMatrix(const I3DMatrix &matrix) 
{
	_matrix = matrix.getMatrix() * _matrix;
	return *this;
};

I3DObject &Scale::applyLocalMatrix(const I3DMatrix &matrix) 
{
	return applyMatrix(matrix);
}

const glm::mat4 &Scale::getMatrix() const 
{
	return _matrix;
}

Scale::Scale(float x, float y, float z) 
{
	_matrix[0][0] = x;
	_matrix[1][1] = y;
	_matrix[2][2] = z;
	_matrix[3][3] = 1;
}

void Scale::add(float x, float y, float z)
{
	_matrix[0][0] += x;
	_matrix[1][1] += y;
	_matrix[2][2] += z;
}

void Scale::add(const glm::vec3 &vec)
{
	add(vec.x, vec.y, vec.z);
}

Scale &Scale::operator+(const glm::vec3 &vec)
{
	add(vec.x, vec.y, vec.z);
	return *this;
}