#include "VertexBuffer.hpp"
#include <iostream>

VertexBuffer::VertexBuffer(int size)
{
	_size = size;
	_id = new GLuint[_size];
	glGenBuffers(_size, _id);
}

void VertexBuffer::bind(int id) const
{
	glBindBuffer(GL_ARRAY_BUFFER, _id[id]);
}

void VertexBuffer::data(void *data, int datasize) const
{
	std::cerr << "VertexBuffer::data(void*, int) : Use of this constructor is HIGHLY discouraged, as it is not object-oriented. Please use VertexBuffer::data(const VertexBufferData &) instead !" << std::endl;
	std::cerr << "VertexBuffer::data(void*, int) : Use of deprecated function." << std::endl;
	glBufferData(GL_ARRAY_BUFFER, datasize, data, GL_STATIC_DRAW);
}

void VertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(_size, _id);
	delete _id;
}