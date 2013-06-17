#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

#include "IShader.hpp"

class IShader;

class IProgram
{
public:
	virtual void attach(const IShader &id) const = 0;
	virtual void link() const = 0;
	virtual GLuint getId() const = 0;
	virtual GLuint getAttribLocation(const std::string &attrib) const = 0;
	virtual ~IProgram() {}
};