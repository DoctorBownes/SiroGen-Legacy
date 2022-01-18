#include "input.h"

void Input::Init(GLFWwindow* window)
{
	_window = window;
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
}

bool Input::KeyInput(KeyCode key, KeyState state)
{
	if (state == GLFW_PRESS)
	{
		if (glfwGetKey(_window, key))
		{
			return true;
		}
	}
	else
	{
		if (glfwGetKey(_window, key))
		{
			keyreleased[key] = 1;
		}
		if (glfwGetKey(_window, key) == state && keyreleased[key])
		{
			keyreleased[key] = 0;
			return true;
		}
	}
	return false;
}

bool Input::MouseInput(MouseButton button, KeyState state)
{
	if (state == GLFW_PRESS)
	{
		if (glfwGetMouseButton(_window, button))
		{
			return true;
		}
	}
	else
	{
		if (glfwGetMouseButton(_window, button))
		{
			mousereleased[button] = 1;
		}
		if (glfwGetMouseButton(_window, button) == state && mousereleased[button])
		{
			mousereleased[button] = 0;
			return true;
		}
	}
	return false;
}
