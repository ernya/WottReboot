#include "I3DMatrix.hpp"
#include "GeometryHandler.hpp"

GeometryHandler::GeometryHandler(int size) : _vbd(4, size * 4), _points(size)
{
}

void GeometryHandler::setSize(int size)
{
	_points.resize(size);
}

glm::vec4 &GeometryHandler::operator[](int idx)
{
	return _points[idx];
}

void GeometryHandler::add(glm::vec4 &pt)
{
	_points.push_back(pt);
}

void GeometryHandler::add(glm::vec3 &pt)
{
	_points.push_back(glm::vec4(pt, 1));
}

void GeometryHandler::set(glm::vec4 &pt, int idx)
{
	_points[idx] = pt;
}

void GeometryHandler::set(glm::vec3 &pt, int idx)
{
	_points[idx] = glm::vec4(pt, 1);
}

VertexBufferData<float> &GeometryHandler::getVectorBufferData()
{
	return _vbd;
}

void GeometryHandler::generateVBD()
{
	_vbd.resize(_points.size() * 4);
	int i = 0;
	for (std::vector<glm::vec4>::iterator it = _points.begin() ; it != _points.end() ; ++it)
	{
		for (int j = 0 ; j < 4 ; ++j)
			_vbd[i + j] = (*it)[j];
		i += 4;
	}
}

I3DObject &GeometryHandler::applyMatrix(const I3DMatrix &matrix)
{
	for (int i = 0 ; i < _points.size() * 4 ; i += 4)
	{
		glm::vec4 point = matrix.getMatrix() * glm::vec4(_vbd[i], _vbd[i + 1], _vbd[i + 2], _vbd[i + 3]);
		_vbd[i] = point[0];
		_vbd[i + 1] = point[1];
		_vbd[i + 2] = point[2];
		_vbd[i + 3] = point[3];
	}
	return *this;
}