#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

class VertexArray
{
private:
	GLuint *_id;
	int	_size;
public:
	enum Mode
	{
		POINTS = GL_POINTS,
		LINE_STRIP = GL_LINE_STRIP,
		LINE_LOOP = GL_LINE_LOOP,
		LINES = GL_LINES,
		LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY,
		LINES_ADJACENCY = GL_LINES_ADJACENCY,
		TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
		TRIANGLE_FAN = GL_TRIANGLE_FAN,
		TRIANGLES = GL_TRIANGLES,
		TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
		TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY,
		PATCHES = GL_PATCHES
	};
	static void drawArrays(Mode mode, GLsizei numberOfVerticesPerArray);
	VertexArray(int size = 1);
	void bind(int id = 0);
	void unbind();
	~VertexArray();
};
