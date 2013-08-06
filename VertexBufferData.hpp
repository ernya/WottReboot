#pragma once

#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

template<typename T>
class VertexBufferData
{
public:
	enum VerticesType
	{
		BYTE = GL_BYTE,
		UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
		SHORT = GL_SHORT,
		UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
		INT = GL_INT,
		UNSIGNED_INT = GL_UNSIGNED_INT,
		HALF_FLOAT = GL_HALF_FLOAT,
		FLOAT = GL_FLOAT,
		DOUBLE = GL_DOUBLE,
		FIXED = GL_FIXED,
		INT_2_10_10_10_REV = GL_INT_2_10_10_10_REV,
		UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
	};
protected:
	std::vector<T> _vertices;
	VerticesType _type;
	GLint	_components;
public:

	VertexBufferData(int components = 4, int size = 0) : _vertices(size)
	{
		throw std::runtime_error("Wrong template type for VertexBufferData");
	}

	T &operator[](int index)
	{
		return _vertices[index];
	}

	const T &operator[](int index) const
	{
		return _vertices.at(index);
	}

	const std::vector<T> getVertices() const
	{
		return _vertices;
	}

	VerticesType getType() const
	{
		return _type;
	}

	void resize(int size)
	{
		_vertices.resize(size);
	}

	int getComponents() const
	{
		return _components;
	}
};



template<>
inline VertexBufferData<float>::VertexBufferData(int components, int size) : _vertices(size), _type(FLOAT), _components(components)
{
}

template<>
inline VertexBufferData<char>::VertexBufferData(int components, int size) : _vertices(size), _type(BYTE), _components(components)
{
}

template<>
inline VertexBufferData<unsigned char>::VertexBufferData(int components, int size) : _vertices(size), _type(UNSIGNED_BYTE), _components(components)
{
}

template<>
inline VertexBufferData<short>::VertexBufferData(int components, int size) : _vertices(size), _type(SHORT), _components(components)
{
}

template<>
inline VertexBufferData<unsigned short>::VertexBufferData(int components, int size) : _vertices(size), _type(UNSIGNED_SHORT), _components(components)
{
}


template<>
inline VertexBufferData<int>::VertexBufferData(int components, int size) : _vertices(size), _type(INT), _components(components)
{
}

template<>
inline VertexBufferData<unsigned int>::VertexBufferData(int components, int size) : _vertices(size), _type(UNSIGNED_INT), _components(components)
{
}

template<>
inline VertexBufferData<double>::VertexBufferData(int components, int size) : _vertices(size), _type(DOUBLE), _components(components)
{
}