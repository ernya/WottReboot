#include "VertexArray.hpp"

VertexArray::VertexArray(int size)
{
	_id = new GLuint[size];
	glGenVertexArrays(size, _id);
	_size = size;
}

void VertexArray::bind(int id)
{
	glBindVertexArray(_id[id]);
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
}

void VertexArray::drawArrays(Mode mode, GLsizei numberOfVerticesPerArray)
{
	glDrawArrays(mode, 0, numberOfVerticesPerArray);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(_size, _id);
	delete _id;
}