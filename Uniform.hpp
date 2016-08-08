#pragma once

#include <iostream>
#include <exception>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "VertexBufferData.hpp"
#include "Logging.hpp"
#include "I3DMatrix.hpp"
#include "Camera.hpp"
#include "IProgram.hpp"

class Uniform
{
protected:
  GLuint _id;
  Uniform() {throw std::runtime_error("Tried to call Uniform() : Invalid Operation !");}
public:
  Uniform(GLuint id);
  Uniform(const IProgram &program, const std::string &uniformName);
  GLuint getId() const;
  void fromI3DMatrix(const I3DMatrix &matrix) const;
  void fromCamera(const Camera *camera) const;
  void fromMat4(const glm::mat4 &matrix) const;
  ~Uniform();
};
