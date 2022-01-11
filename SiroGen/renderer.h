#pragma once
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
	GLFWwindow* window;
private:
	void RenderEntity(glm::mat4 mat, Entity* entity);
	void RenderMesh(GLuint frame, GLuint sprite, GLuint uv);
	GLuint _shader;
	Camera* _camera = new Camera();
	GLuint GetShader(const char* vertex_file_path, const char* fragment_file_path);
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

