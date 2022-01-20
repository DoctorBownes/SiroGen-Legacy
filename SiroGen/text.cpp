#include "text.h"

void Text::initText2D(const char* texturePath)
{

}

void Text::printText2D(const char* text, int x, int y, int size)
{
	std::vector<glm::vec2> vertices;
	std::vector<glm::vec2> UVs;
	int count = 0;
	for (int i = 0; text[i]; i++)
	{
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		glm::vec2 vertex_up_left = glm::vec2(x + i * size, y + size);
		glm::vec2 vertex_up_right = glm::vec2(x + i * size + size, y + size);
		glm::vec2 vertex_down_left = glm::vec2(x + i * size, y);
		glm::vec2 vertex_down_right = glm::vec2(x + i * size + size, y);

		vertices.push_back(vertex_up_left);
		vertices.push_back(vertex_down_left);
		vertices.push_back(vertex_up_right);

		vertices.push_back(vertex_down_right);
		vertices.push_back(vertex_up_right);
		vertices.push_back(vertex_down_left);

		char character = text[i];
		float uv_x = (character & 16) / 16.0f;
		float uv_y = (character / 16) / 16.0f;

		glm::vec2 uv_up_left = glm::vec2(uv_x, 1.0f - uv_y);
		glm::vec2 uv_up_right = glm::vec2(uv_x+1.0f/16.0f, 1.0f - uv_y);
		glm::vec2 uv_down_left = glm::vec2(uv_x + 1.0f / 16.0f, 1.0f - (uv_y + 1.0f / 16.0f));
		glm::vec2 uv_down_right = glm::vec2(uv_x, 1.0f - (uv_y + 1.0f / 16.0f));

		UVs.push_back(uv_up_left);
		UVs.push_back(uv_down_left);
		UVs.push_back(uv_up_right);

		UVs.push_back(uv_down_right);
		UVs.push_back(uv_up_right);
		UVs.push_back(uv_down_left);

	}

}

void Text::cleanupText2D()
{

}