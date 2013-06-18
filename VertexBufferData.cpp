#include "VertexBufferData.hpp"

template<>
VertexBufferData<char>::VertexBufferData(int components, int size) : _vertices(size), _type(BYTE), _components(components)
{
}

template<>
VertexBufferData<unsigned char>::VertexBufferData(int components, int size) : _vertices(size), _type(UNSIGNED_BYTE), _components(components)
{
}

template<>
VertexBufferData<short>::VertexBufferData(int components, int size) : _vertices(size), _type(SHORT), _components(components)
{
}

template<>
VertexBufferData<unsigned short>::VertexBufferData(int components, int size) : _vertices(size), _type(UNSIGNED_SHORT), _components(components)
{
}


template<>
VertexBufferData<int>::VertexBufferData(int components, int size) : _vertices(size), _type(INT), _components(components)
{
}

template<>
VertexBufferData<unsigned int>::VertexBufferData(int components, int size) : _vertices(size), _type(UNSIGNED_INT), _components(components)
{
}

template<>
VertexBufferData<float>::VertexBufferData(int components, int size) : _vertices(size), _type(FLOAT), _components(components)
{
}

template<>
VertexBufferData<double>::VertexBufferData(int components, int size) : _vertices(size), _type(DOUBLE), _components(components)
{
}

