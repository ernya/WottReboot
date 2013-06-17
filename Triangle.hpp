#pragma once

#include "Program.hpp"
#include "SimpleFragmentShader.hpp"
#include "SimpleVertexShader.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "IDrawable.hpp"
#include "IUpdatable.hpp"
#include "VertexBufferData.hpp"
#include "VertexAttrib.hpp"

class Triangle : public IDrawable, public IUpdatable
{
private:
	Window *_win;
	VertexAttrib *_va;
	VertexArray _vao;
	VertexBuffer _vbo;
	VertexBufferData<float>	*_vbd;
	SimpleFragmentShader *_fs;
	SimpleVertexShader *_vs;
	Program *_program;
public :
	Triangle();
	void init(Window *win);
	void load();
	void draw();
	void update();
	void unload();
	~Triangle();
};
