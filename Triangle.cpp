#include "Triangle.hpp"
#include "Translation.hpp"

Triangle::Triangle()
{
	srand(4242);
}

void Triangle::init(Window *win)
{
	_fs = new SimpleFragmentShader();
	_vs = new SimpleVertexShader();
	_fs->compile();
	_vs->compile();
	_program = new Program();
	_program->attach(*_fs);
	_program->attach(*_vs);
	_program->link();
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
	_va = new VertexAttrib(*_program, "vertexPosition_modelspace");
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
	Translation t(0.001, 0, 0);
	applyMatrix(t);
	_vao.bind();
	_vbo.bind();
	_vbo.data(*_vbd);
	_vbo.unbind();
	_vao.unbind();
}

void Triangle::draw()
{
	_program->useProgram();
	_vao.bind();
	_va->enable();
	VertexArray::drawArrays(VertexArray::TRIANGLES, 3);
	_va->disable();
	_vao.unbind();
	_program->stopUseProgram();
}

void Triangle::unload()
{
}

I3DObject &Triangle::applyMatrix(const I3DMatrix &matrix)
{
	glm::vec4 pt1;
	pt1[0] = (*_vbd)[0];
	pt1[1] = (*_vbd)[1];
	pt1[2] = (*_vbd)[2];
	pt1[3] = 1;
	glm::vec4 pt2;
	pt2[0] = (*_vbd)[3];
	pt2[1] = (*_vbd)[4];
	pt2[2] = (*_vbd)[5];
	pt2[3] = 1;
	glm::vec4 pt3;
	pt3[0] = (*_vbd)[6];
	pt3[1] = (*_vbd)[7];
	pt3[2] = (*_vbd)[8];
	pt3[3] = 1;
	glm::vec4 pt1_ = matrix.getMatrix() * pt1;
	glm::vec4 pt2_ = matrix.getMatrix() * pt2;
	glm::vec4 pt3_ = matrix.getMatrix() * pt3;
	(*_vbd)[0] = pt1_[0];
	(*_vbd)[1] = pt1_[1];
	(*_vbd)[2] = pt1_[2];
	(*_vbd)[3] = pt2_[0];
	(*_vbd)[4] = pt2_[1];
	(*_vbd)[5] = pt2_[2];
	(*_vbd)[6] = pt3_[0];
	(*_vbd)[7] = pt3_[1];
	(*_vbd)[8] = pt3_[2];
	return *this;
}

Triangle::~Triangle()
{
	delete _vbd;
	delete _va;
}