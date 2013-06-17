#pragma once

#include <iostream>

#include "IShader.hpp"

class AShader : public IShader
{
protected:
	GLuint _id;
	const std::string _shader;
public:
	enum SHADER_TYPE
	{
		VERTEX_SHADER,
		FRAGMENT_SHADER
	};

	GLuint getId() const 
	{
		return _id;
	}

	bool compile() const
	{
		const char *tmp = _shader.c_str();
		glShaderSource(_id, 1, &tmp, NULL);
		glCompileShader(_id);
		GLint error;
		glGetShaderiv (_id, GL_COMPILE_STATUS, &error);
		if (error != GL_TRUE)
			return false;
		return true;
	}

	AShader(const std::string &shader, SHADER_TYPE type) : _shader(shader) 
	{
		_id = glCreateShader(type == VERTEX_SHADER ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
	}
};