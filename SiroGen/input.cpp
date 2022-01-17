#include "input.h"

void Input::Init(GLFWwindow* window)
{
	_window = window;
}

bool Input::KeyInput(KeyCode key, KeyState state)
{
	if (glfwGetKey(_window, key) == state)
	{
		return true;
	}
	return false;
}