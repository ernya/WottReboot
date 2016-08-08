#pragma once

#include <glm/glm.hpp>

class Camera
{
protected:
  glm::mat4 _viewMatrix;
  glm::vec3 _position;
  glm::vec3 _target;
  float		_fov;
  
public:
  Camera() : _position(glm::vec3(0,0,0)), _fov(45), _target(glm::vec3(0,0,0)) {}
  Camera(float x, float y, float z);
  Camera(glm::vec3 pos);
  void move(float x, float y, float z);
  void move(glm::vec3 pos);
  void setPosition(float x, float y, float z);
  void setPosition(glm::vec3 pos);
  void lookAt(glm::vec3 pos, glm::vec3 target);
  void lookAt(glm::vec3 target);
  void setFoV(float newFov);

  float getFoV() const;
  const glm::mat4 &getMatrix() const;

};
