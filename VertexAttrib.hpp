#pragma once

#include <iostream>
#include <exception>
#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include "VertexBufferData.hpp"
#include "IProgram.hpp"

class VertexAttrib
{
protected:
	GLuint _id;
	VertexAttrib() {throw std::runtime_error("Tried to call VertexAttrib() : Invalid Operation !");}
public:
	VertexAttrib(GLuint id);
	VertexAttrib(const IProgram &program, const std::string &attrib);
	void enable() const;
	void disable() const;
	GLuint getId() const;
	template<typename T>
	void pointer(const VertexBufferData<T> &_vbd, void *offset = NULL) const
	{
		glVertexAttribPointer(_id, _vbd.getComponents(), _vbd.getType(), GL_FALSE, 0, offset);
	}
	~VertexAttrib();
};