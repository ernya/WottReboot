#pragma once

#include "Program.hpp"
#include "SimpleFragmentShader.hpp"
#include "SimpleVertexShader.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "ADrawable.hpp"
#include "IUpdatable.hpp"
#include "Uniform.hpp"
#include "VertexBufferData.hpp"
#include "VertexAttrib.hpp"
#include "I3DObject.hpp"

class Triangle : public ADrawable, public AUpdatable
{
private:
	Window *_win;
	VertexAttrib *_va;
	VertexArray _vao;
	VertexBuffer _vbo;
	Uniform *_modelMatrix;
	Uniform *_viewMatrix;
	SimpleFragmentShader *_fs;
	SimpleVertexShader *_vs;
	Program *_program;
public :
	Triangle(float x = 0, float y = 0, float z = 0);
	void internalLoad();
	void init(Window *win);
	void load();
	void draw(const glm::mat4 &viewProjectionMatrix);
	void update();
	void unload();
	I3DObject &applyMatrix(const I3DMatrix &matrix);
	~Triangle();
};
