#pragma once
#include <glm/glm.hpp>
#include "I3DMatrix.hpp"

class TransformationMatrix : public I3DMatrix
{
protected:
  glm::mat4 _matrix;
  TransformationMatrix() {}
public:
  const glm::mat4 &getMatrix() const { return _matrix; }
  TransformationMatrix(const glm::mat4 &matrix) : _matrix(matrix) {}
  I3DObject &applyMatrix(const I3DMatrix &matrix) 
  {
	_matrix = matrix.getMatrix() * _matrix;
	return *this;
  }
};
