#include "VertexAttrib.hpp"

VertexAttrib::VertexAttrib(GLuint id)
{
	std::cerr << "VertexAttrib(GLuint) : Use of this constructor is HIGHLY discouraged, as it is not object-oriented. Please use VertexAttrib(const IProgram &, const std::string &) instead !" << std::endl;
	std::cerr << "VertexAttrib(GLuint) : Use of deprecated function." << std::endl;
	_id = id;
}

VertexAttrib::VertexAttrib(const IProgram &program, const std::string &attribute)
{
	_id = program.getAttribLocation(attribute);
}

void VertexAttrib::enable() const
{
	glEnableVertexAttribArray(_id);
}

void VertexAttrib::disable() const
{
	glDisableVertexAttribArray(_id);
}


VertexAttrib::~VertexAttrib()
{
}