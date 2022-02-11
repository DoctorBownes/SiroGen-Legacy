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
	void RenderText(Text text);
	GLuint _shader;
	Camera* _camera = new Camera();
	GLuint GetShader(const char* vertex_file_path, const char* fragment_file_path);
    //Based on ZX Spectrum color palette.
    const Color Palette[16] =
    {
        ALPHA, //0
        BLACK, //1
        DARKBLUE, //2
        BLUE, //3
        DARKRED, //4
        RED, //5
        DARKMAGENTA, //6
        MAGENTA, //7
        DARKGREEN, //8
        GREEN, //9
        DARKCYAN, //10
        CYAN, //11
        DARKYELLOW, //12
        YELLOW, //13
        GRAY, //14
        WHITE //15
    };
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

