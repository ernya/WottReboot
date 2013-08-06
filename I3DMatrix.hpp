#pragma once

#include <glm\glm.hpp>
#include "I3DObject.hpp"

class I3DMatrix : public I3DObject
{
public:
	I3DMatrix() {};
	virtual const glm::mat4 &getMatrix() const = 0;
};