#pragma once
#include <vector>
#include <SiroGen/texture.h>
#include <SiroGen/component.h>
#include <glm/glm.hpp>

class Text : public Component
{
public:
	void initText2D(const char* texturePath);
	void printText2D(const char* text, float x, float y, float size, uint8_t Color = 0xf, const char* TGAfont = "assets/LucidaConsole.tga");
	void cleanupText2D();
	virtual void DoIt(GLuint shader);

private:

	Color textColor;

	Texture* _texture;
	GLfloat* vertex_buffer_data;
	GLfloat* uv_buffer_data;
	std::vector<GLfloat> vertex_buffer_vector;
	std::vector<GLfloat> uv_buffer_vector;

	GLuint texture_buffer;
	GLuint vertex_buffer;
	GLuint uv_buffer;

	int _count = 1;
};
