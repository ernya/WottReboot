#include <glm/gtc/matrix_transform.hpp>
#include "Camera.hpp"

Camera::Camera(float x, float y, float z)
{
  setPosition(x,y,z);
}

Camera::Camera(glm::vec3 pos)
{
  setPosition(pos);
}

void Camera::move(float x, float y, float z)
{
  move(glm::vec3(x,y,z));
}

void Camera::move(glm::vec3 pos)
{
  _position += pos;
}

void Camera::setPosition(float x, float y, float z)
{
  setPosition(glm::vec3(x,y,z));
}

void Camera::setPosition(glm::vec3 pos)
{
  _position = pos;
}

void Camera::lookAt(glm::vec3 pos, glm::vec3 target)
{
  setPosition(pos);
  lookAt(target);
}

void Camera::lookAt(glm::vec3 target)
{
  _viewMatrix = glm::lookAt(_position, target, glm::vec3(0,1,0));
}

const glm::mat4 &Camera::getMatrix() const
{
  return _viewMatrix;
}
