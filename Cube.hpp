#pragma once

#include "Uniform.hpp"
#include "Program.hpp"
#include "SimpleFragmentShader.hpp"
#include "SimpleVertexShader.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "ADrawable.hpp"
#include "IUpdatable.hpp"
#include "VertexBufferData.hpp"
#include "VertexAttrib.hpp"
#include "I3DObject.hpp"

class Cube : public ADrawable, public IUpdatable
{
private:
	Window *_win;
	VertexAttrib *_va;
  Uniform *_modelMatrix;
  VertexArray _vao;
	VertexBuffer _vbo;
	SimpleFragmentShader *_fs;
	SimpleVertexShader *_vs;
	Program *_program;
public :
	Cube(float x = 0, float y = 0, float z = 0);
	void internalLoad();
	void init(Window *win);
	void load();
	void draw();
	void update();
	void unload();
	I3DObject &applyMatrix(const I3DMatrix &matrix);
	~Cube();
};
