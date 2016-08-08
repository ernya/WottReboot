#include "Triangle.hpp"
#include "Translation.hpp"
#include "Scale.hpp"
#include "Rotation.hpp"

Triangle::Triangle(float x, float y, float z)
{
	translate(x, y, z);
}

void Triangle::init(Window *win)
{
	_fs = new SimpleFragmentShader();
	_vs = new SimpleVertexShader();
	
	_program = new Program();
	_win = win;
	_modelMatrix = NULL;
	_viewMatrix = NULL;
	_camera = NULL;

}

static void callback(Triangle *ptr)
{
	ptr->internalLoad();
}

void Triangle::load()
{
	_geometry.add(glm::vec3(-1.0f, -1.0f, 0.0f));
	_geometry.add(glm::vec3(1.0f, -1.0f, 0.0f));
	_geometry.add(glm::vec3(0.0f, 1.0f, 0.0f));
	_win->execOnRenderingThread(callback, Window::ExecutionPriority::HIGHEST, this);
}

void Triangle::internalLoad()
{
	_fs->compile();
	_vs->compile();
	_program->attach(*_fs);
	_program->attach(*_vs);
	_program->link();
	_va = new VertexAttrib(*_program, "vertexPosition_modelspace");
	_modelMatrix = new Uniform(*_program, "modelMatrix");
	_viewMatrix = new Uniform(*_program, "viewMatrix");
	_vao.bind();
	_vbo.bind();
	_vbo.data(_geometry.getVertexBufferData());
	_va->enable();
	_va->geometryPointer(_geometry.getVertexBufferData());
	_va->disable();
	_vbo.unbind();
	_vao.unbind();
	setScale(0.75, 0.75, 0.75);
	_isLoaded = true;
}

void Triangle::update()
{
	rotate(0, 0, 0.001);
	_vao.bind();
	_vbo.bind();
	_vbo.data(_geometry.getVertexBufferData());
	_vbo.unbind();
	_vao.unbind();
}

void Triangle::draw(const glm::mat4 &viewProjectionMatrix)
{
	if (_camera == NULL)
		_camera = _win->getMainCamera();
	_program->useProgram();
	_viewMatrix->fromCamera(_camera);
	_modelMatrix->fromMat4(viewProjectionMatrix);
	_vao.bind();
	_va->enable();
	VertexArray::drawArrays(VertexArray::TRIANGLE_STRIP, 3);
	_va->disable();
	_vao.unbind();
	_program->stopUseProgram();
}

void Triangle::unload()
{
	delete _va;
	delete _modelMatrix;
	delete _viewMatrix;
}

I3DObject &Triangle::applyMatrix(const I3DMatrix &matrix)
{
	Logging::severe("[PERFORMANCE] Function disabled.");
	/*if (_modelMatrix)
	{
		_program->useProgram();
		_modelMatrix->fromI3DMatrix(matrix);
		if (_camera == NULL)
			_camera = _win->getMainCamera();
		_viewMatrix->fromCamera(_camera);
		_program->stopUseProgram();
	}*/
	return *this;
}

Triangle::~Triangle()
{
	delete _vs;
	delete _fs;
	delete _program;
}
