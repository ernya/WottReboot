#pragma once

class I3DMatrix;

class I3DObject
{
public:
	virtual I3DObject &applyMatrix(const I3DMatrix &matrix) = 0;
};