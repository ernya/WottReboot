#pragma once

#include <glm/glm.hpp>
#include "I3DMatrix.hpp"

class Scale : public I3DMatrix
{
protected:
	glm::mat4 _matrix;
public:
	const glm::mat4 &getMatrix() const;
	Scale() { Scale(1, 1, 1); };
	Scale(float x, float y, float z);
	void setX(float x) {_matrix[0][0] = x; }
	void setY(float y) {_matrix[1][1] = y; }
	void setZ(float z) {_matrix[2][2] = z; }
	void add(float x, float y, float z);
	void add(const glm::vec3 &vec);
	Scale &operator+(const glm::vec3 &vec);
	I3DObject &applyMatrix(const I3DMatrix &matrix);
	I3DObject &applyLocalMatrix(const I3DMatrix &matrix);
};
