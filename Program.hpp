#pragma once

#include <iostream>

#include "IProgram.hpp"

class Program : public IProgram
{
protected:
	GLuint _id;
public:
	Program()
	{
		_id = glCreateProgram();
	}

	void link() const
	{
		glLinkProgram(_id);
		GLint error;
		glGetProgramiv(_id, GL_LINK_STATUS, &error);
		if (error != GL_TRUE)
		{
			glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &error);
			char *errorlog = new char[error];
			glGetProgramInfoLog(_id, error, NULL, errorlog);
			std::cerr << "FAIL LINK" << std::endl;
			std::cerr << errorlog << std::endl;
		}
	}

	void attach(const IShader &id) const
	{
		glAttachShader(_id, id.getId());
	}

	void useProgram() const
	{
		glUseProgram(_id);
	}

	void stopUseProgram() const
	{
		glUseProgram(0);
	}

	GLuint getAttribLocation(const std::string &attrib) const
	{
		return glGetAttribLocation(_id, attrib.c_str());
	}
};