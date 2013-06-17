#include "Triangle.hpp"

Triangle::Triangle()
{
	srand(4242);
}

void Triangle::init(Window *win)
{
	/*_fs = new SimpleFragmentShader();
	_vs = new SimpleVertexShader();
	_fs->compile();
	_vs->compile();
	_program = new Program();
	_program->attach(*_fs);
	_program->attach(*_vs);
	_program->link();*/
	_win = win;
	_vbd = new VertexBufferData<float>(3, 9);
	(*_vbd)[0] = -1.0f;
	(*_vbd)[1] = -1.0f;
	(*_vbd)[2] = 0.0f;
	(*_vbd)[3] = 1.0f;
	(*_vbd)[4] = -1.0f;
	(*_vbd)[5] = 0.0f;
	(*_vbd)[6] = 0.0f;
	(*_vbd)[7] = 1.0f;
	(*_vbd)[8] = 0.0f;
	_va = new VertexAttrib(0);
	_vao.bind();
	_vbo.bind();
	_vbo.data(*_vbd);
	_vbo.unbind();
	_vao.unbind();
}

void Triangle::load()
{
	_vao.bind();
	_vbo.bind();
	_va->enable();
	_va->pointer(*_vbd);
	_va->disable();
	_vbo.unbind();
	_vao.unbind();
}

void Triangle::update()
{
	for (int i = 0 ; i < 9 ; ++i)
	{
		(*_vbd)[i] = ((float)(rand() % 10000) - 5000) / 5000;
	}
	_vao.bind();
	_vbo.bind();
	_vbo.data(*_vbd);
	_vbo.unbind();
	_vao.unbind();
}

void Triangle::draw()
{
	_vao.bind();
	_va->enable();
	VertexArray::drawArrays(VertexArray::LINE_LOOP, 3);
	_va->disable();
	_vao.unbind();
}

void Triangle::unload()
{
}

Triangle::~Triangle()
{
	delete _vbd;
	delete _va;
}