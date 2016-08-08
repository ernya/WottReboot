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

class Cube : public ADrawable, public AUpdatable
{
private:
	Window *_win;
  Camera *_camera;
  VertexAttrib *_va;
  Uniform *_modelMatrix;
  Uniform *_viewMatrix;
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
	void draw(const glm::mat4 &viewProjectionMatrix);
	void update();
	void unload();
	I3DObject &applyMatrix(const I3DMatrix &matrix);
	~Cube();
};
