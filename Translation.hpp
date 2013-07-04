#pragma once

#include <glm/glm.hpp>
#include "I3DMatrix.hpp"

class Translation : public I3DMatrix
{
protected:
	glm::mat4 _matrix;
public:
	const glm::mat4 &getMatrix() const;
	Translation(float x, float y, float z) 
	{
		_matrix[0][0] = 1;
		_matrix[1][1] = 1;
		_matrix[2][2] = 1;
		_matrix[3][3] = 1;
		_matrix[3][0] = x;
		_matrix[3][1] = y;
		_matrix[3][2] = z;
	}
	void setX(float x) {_matrix[3][0] = x; }
	void setY(float y) {_matrix[3][1] = y; }
	void setZ(float z) {_matrix[3][2] = z; }
	I3DObject &applyMatrix(const I3DMatrix &matrix);
};