#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

class IShader
{
public:
	virtual bool compile() const = 0;
	virtual GLuint getId() const = 0;
	virtual ~IShader() {}
};