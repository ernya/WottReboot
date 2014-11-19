#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "I3DObject.hpp"
#include "VertexBufferData.hpp"

class GeometryHandler : public I3DObject
{
	std::vector<glm::vec4> _points;
	VertexBufferData<float> _vbd;
public:
	GeometryHandler(int size = 0);
	void setSize(int size);
	glm::vec4 &operator[](int idx);
	void add(const glm::vec4 &pt);
	void add(const glm::vec3 &pt);
	void set(glm::vec4 &pt, int idx);
	void set(glm::vec3 &pt, int idx);
	VertexBufferData<float> &getVertexBufferData();
	void generateVBD();
	I3DObject &applyMatrix(const I3DMatrix &matrix);
  int getSize() const;
};
