#pragma once

#pragma once

#include <glm/glm.hpp>
#include "I3DMatrix.hpp"

class Rotation : public I3DMatrix
{
private:
	void refreshMatrix();
protected:
	float _x;
	float _y;
	float _z;
	glm::mat4 _matrix;
public:
	const glm::mat4 &getMatrix() const;
	Rotation() : _x(0), _y(0), _z(0) {}
	Rotation(float x, float y, float z);
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void add(float x, float y, float z);
	void add(const glm::vec3 &vec);
	Rotation &operator+(const glm::vec3 &vec);
	I3DObject &applyMatrix(const I3DMatrix &matrix);
	I3DObject &applyLocalMatrix(const I3DMatrix &matrix);
};