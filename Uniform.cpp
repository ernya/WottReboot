#include "Uniform.hpp"

Uniform::Uniform(GLuint id) : _id(id)
{
  Logging::warning("Uniform(GLuint) : Use of this constructor is HIGHLY discouraged, as it is not object-oriented. Please use Uniform(const IProgram &, const std::string &) instead !");
  Logging::warning("Uniform(GLuint) : Use of deprecated function.");
}

Uniform::Uniform(const IProgram &program, const std::string &uniformName)
{
  _id = program.getUniformLocation(uniformName);
}

GLuint Uniform::getId() const
{
  return _id;
}

void Uniform::fromMat4(const glm::mat4 &matrix) const
{
  glUniformMatrix4fv(_id, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Uniform::fromI3DMatrix(const I3DMatrix &matrix) const
{
  fromMat4(matrix.getMatrix());
}

Uniform::~Uniform()
{
}
