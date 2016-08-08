#pragma once

#include <glm/glm.hpp>
#include "I3DMatrix.hpp"

class Translation : public I3DMatrix
{
protected:
	glm::mat4 _matrix;
	glm::vec3 _vector;
public:
	const glm::mat4 &getMatrix() const;
	Translation() {}
	Translation(float x, float y, float z);
	void setX(float x) {
		_matrix[3][0] = x;
		_vector[0] = x;
	}
	void setY(float y) {
		_matrix[3][1] = y;
		_vector[1] = y;
	}
	void setZ(float z) {
		_matrix[3][2] = z;
		_vector[2] = z;
	}
	void add(float x, float y, float z);
	void add(const glm::vec3 &vec);
	Translation &operator+(const glm::vec3 &vec);
	I3DObject &applyMatrix(const I3DMatrix &matrix);
	I3DObject &applyLocalMatrix(const I3DMatrix &matrix);

	const glm::vec3 &getVector() const { return _vector; }
};