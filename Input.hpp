#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

using namespace glm;

class Input
{
public:
	Input(void);
	void init() const;
	int getKey(int key) const;
	bool isPressed(int key) const;
	virtual ~Input(void);
};

