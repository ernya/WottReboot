#pragma once

#include <iostream>

#include "IProgram.hpp"

class Program : IProgram
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
	}

	void attach(const IShader &id) const
	{
		glAttachShader(_id, id.getId());
	}

	GLuint getId() const
	{
		return _id;
	}

	GLuint getAttribLocation(const std::string &attrib) const
	{
		return glGetAttribLocation(_id, attrib.c_str());
	}
};