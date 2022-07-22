#ifndef RENDERER_H_
#define RENDERER_H_
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <fstream>
#include <cerrno>

#include <SiroGen/scene.h>

std::string get_file_contents(const char* filename);

class Renderer
{
public:
	Renderer();
	~Renderer();
	void RenderScene(Scene* scene);
	void SetWorldPosition(glm::mat4 mat, Entity* entity);
	GLFWwindow* _window = nullptr;
private:
	bool test = false;
	glm::mat4 initmat = glm::mat4(1);
	void RenderEntity(glm::mat4 mat, Entity* entity);
	void RenderText(Text* text);
	GLuint _shader = 0;
	Camera* _camera = nullptr;
	GLuint GetShader(const char* vertex_file_path, const char* fragment_file_path);
	Palette* _palette = _palette->GetInstance();
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif
