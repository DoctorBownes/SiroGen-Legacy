#include "input.h"

void Input::Init(GLFWwindow* window)
{
	_window = window;
	GetMousePos();
}

bool Input::KeyPressed(KeyCode key)
{
	if (glfwGetKey(_window, key) == GLFW_RELEASE)
	{
		keypressed[key] = 0;
	}
	if (glfwGetKey(_window, key) == GLFW_PRESS && !keypressed[key])
	{
		keypressed[key] = 1;
		return true;
	}
	return false;
}

bool Input::KeyReleased(KeyCode key)
{
	if (glfwGetKey(_window, key))
	{
		keyreleased[key] = 1;
	}
	if (glfwGetKey(_window, key) == GLFW_RELEASE && keyreleased[key])
	{
		keyreleased[key] = 0;
		return true;
	}
	return false;
}

bool Input::KeyDown(KeyCode key)
{
	if (glfwGetKey(_window, key) == GLFW_PRESS)
	{
		return true;
	}
	return false;
}

bool Input::MousePressed(MouseButton button)
{
	if (glfwGetMouseButton(_window, button) == GLFW_RELEASE)
	{
		mousepressed[button] = 0;
	}
	if (glfwGetMouseButton(_window, button) == GLFW_PRESS && !mousepressed[button])
	{
		mousepressed[button] = 1;
		return true;
	}
	return false;
}

bool Input::MouseReleased(MouseButton button)
{
	if (glfwGetMouseButton(_window, button))
	{
		mousereleased[button] = 1;
	}
	if (glfwGetMouseButton(_window, button) == GLFW_RELEASE && mousereleased[button])
	{
		mousereleased[button] = 0;
		return true;
	}
	return false;
}

bool Input::MouseDown(MouseButton button)
{
	if (glfwGetMouseButton(_window, button) == GLFW_PRESS)
	{
		return true;
	}
	return false;
}

//bool Input::MouseOver(Entity* collider)
//{
//	std::cout << mousecollider->transform->position->x << std::endl;
//	if (mousecollider->GetComponent<Collider>()->isColliding(collider))
//	{
//		return true;
//	}
//	return false;
//}

void Input::GetMousePos()
{
	glfwGetCursorPos(_window, &mousex, &mousey);
}