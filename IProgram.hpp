#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "IShader.hpp"

class IShader;

class IProgram
{
public:
	virtual void attach(const IShader &id) const = 0;
	virtual void link() const = 0;
	virtual void useProgram() const = 0;
	virtual void stopUseProgram() const = 0;
	virtual GLuint getAttribLocation(const std::string &attrib) const = 0;
	virtual ~IProgram() {}
};