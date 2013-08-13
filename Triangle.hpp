#pragma once

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

class Triangle : public ADrawable, public IUpdatable
{
private:
	Window *_win;
	VertexAttrib *_va;
	VertexArray _vao;
	VertexBuffer _vbo;
	SimpleFragmentShader *_fs;
	SimpleVertexShader *_vs;
	Program *_program;
public :
	Triangle();
	void internalLoad();
	void init(Window *win);
	void load();
	void draw();
	void update();
	void unload();
	I3DObject &applyMatrix(const I3DMatrix &matrix);
	~Triangle();
};
