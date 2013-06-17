#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

#include "VertexBufferData.hpp"

class VertexBuffer
{
private:
	GLuint *_id;
	int _size;
public:
	VertexBuffer(int size = 1);
	void bind(int id = 0) const;
	void data(void *data, int datasize) const;
	template <typename T>
	void data(const VertexBufferData<T> &vbd) const
	{
		const std::vector<T> &tmp = vbd.getVertices();
		glBufferData(GL_ARRAY_BUFFER, tmp.size() * sizeof(T), tmp.data(), GL_STATIC_DRAW);
	}
	void unbind();
	~VertexBuffer();
};
