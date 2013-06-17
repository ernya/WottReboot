#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

class IShader
{
public:
	virtual bool compile() const = 0;
	virtual GLuint getId() const = 0;
	virtual ~IShader() {}
};