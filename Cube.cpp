#include "Cube.hpp"
#include "Translation.hpp"
#include "Scale.hpp"
#include "Rotation.hpp"
#include <glm/gtx/string_cast.hpp>
Cube::Cube(float x, float y, float z) : _modelMatrix(NULL)
{
	translate(x, y, z);
}

void Cube::init(Window *win)
{
	_fs = new SimpleFragmentShader();
	_vs = new SimpleVertexShader();
	
	_program = new Program();
	_win = win;
}

static void callback(Cube *ptr)
{
	ptr->internalLoad();
}

void Cube::load()
{
	_geometry.add(glm::vec3(-1.0f, -1.0f, 1.0f));
	_geometry.add(glm::vec3(-1.0f, 1.0f, 1.0f));
	_geometry.add(glm::vec3(1.0f, -1.0f, 1.0f));
	_geometry.add(glm::vec3(1.0f, 1.0f, 1.0f));
	_geometry.add(glm::vec3(1.0f, -1.0f, -1.0f));
	_geometry.add(glm::vec3(1.0f, 1.0f, -1.0f));
	_geometry.add(glm::vec3(-1.0f, -1.0f, -1.0f));
	_geometry.add(glm::vec3(-1.0f, 1.0f, -1.0f));
	_geometry.add(glm::vec3(-1.0f, 1.0f, 1.0f));
	setScale(0.1f, 0.1f, 0.1f);
	_win->execOnRenderingThread(callback, Window::ExecutionPriority::HIGHEST, this);
}

void Cube::internalLoad()
{
	_fs->compile();
	_vs->compile();
	_program->attach(*_fs);
	_program->attach(*_vs);
	_program->link();
	_va = new VertexAttrib(*_program, "vertexPosition_modelspace");
	_modelMatrix = new Uniform(*_program, "modelMatrix");
	_vao.bind();
	_vbo.bind();
	_vbo.data(_geometry.getVertexBufferData());
	_va->enable();
	_va->geometryPointer(_geometry.getVertexBufferData());
	_va->disable();
	_vbo.unbind();
	_vao.unbind();
	_isLoaded = true;
}

void Cube::update()
{
  //translate(0.00f, 0.001f, 0);
  rotate(1, 1, 0);
	applyTransformations();
	_vao.bind();
	_vbo.bind();
	_vbo.data(_geometry.getVertexBufferData());
	_vbo.unbind();
	_vao.unbind();
}

void Cube::draw()
{
	_program->useProgram();
	_vao.bind();
	_va->enable();
	VertexArray::drawArrays(VertexArray::TRIANGLE_STRIP, _geometry.getSize());
	_va->disable();
	_vao.unbind();
	_program->stopUseProgram();
}

void Cube::unload()
{
	delete _va;
	delete _modelMatrix;
}

I3DObject &Cube::applyMatrix(const I3DMatrix &matrix)
{
  if (_modelMatrix)
    {
      _program->useProgram();
      _modelMatrix->fromI3DMatrix(matrix);
      _program->stopUseProgram();
    }
  return *this;
}

Cube::~Cube()
{
	delete _vs;
	delete _fs;
	delete _program;
}
