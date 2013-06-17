#include "Input.hpp"


Input::Input(void)
{
}

void Input::init() const
{
	glfwEnable(GLFW_STICKY_KEYS);
}

int Input::getKey(int key) const
{
	return (glfwGetKey(key));
}

bool Input::isPressed(int key) const
{
	return (glfwGetKey(key) == GLFW_PRESS);
}

Input::~Input(void)
{
}
