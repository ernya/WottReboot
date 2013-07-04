#include "Translation.hpp"

I3DObject &Translation::applyMatrix(const I3DMatrix &matrix) 
	{
		_matrix = matrix.getMatrix() * _matrix;
		return *this;
	};

	const glm::mat4 &Translation::getMatrix() const 
	{
		return _matrix;
	}