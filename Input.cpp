#include "Input.hpp"


Input::Input(void)
{
}

void Input::init(GLFWwindow *win)
{
	_window = win;
	glfwSetInputMode(win, GLFW_STICKY_KEYS, GL_TRUE);
}

int Input::getKey(int key) const
{
	return (glfwGetKey(_window, key));
}

bool Input::isPressed(int key) const
{
	return (glfwGetKey(_window, key) == GLFW_PRESS);
}

Input::~Input(void)
{
}
