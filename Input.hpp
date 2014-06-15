#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>

using namespace glm;

class Input
{
private:
	GLFWwindow *_window;

public:
	Input(void);
	void init(GLFWwindow *);
	int getKey(int key) const;
	bool isPressed(int key) const;
	virtual ~Input(void);
};

