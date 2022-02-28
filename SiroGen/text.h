#ifndef TEXT_H_
#define TEXT_H_
#include <vector>
#include <SiroGen/component.h>
#include <SiroGen/resourcemanager.h>
#include <glm/glm.hpp>

class Text : public Component
{
public:
	Text();
	Text(Entity* owner);
	~Text();
	void SetText(std::string text, float x, float y, float size, uint8_t Color = 0xf, const char* TGAfont = "");
	void EditText(std::string text);
	virtual void DoIt(GLuint shader);

private:
	ResourceManager* _instance = _instance->GetInstance();
	Texture* texture;

	float _x = 0.0f;
	float _y = 0.0f;
	float _size = 0.0f;
	float _linedepth = 0.0f;

	void Init();
	uint8_t textColor;
	std::vector<GLfloat> vertex_buffer_vector;
	std::vector<GLfloat> uv_buffer_vector;

	GLuint texture_buffer;
	GLuint vertex_buffer;
	GLuint uv_buffer;

	int _count = 0;
};
#endif
