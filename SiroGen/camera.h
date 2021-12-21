#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SiroGen/transform.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <iostream>

class Camera
{
public:
	Camera(bool isThreeDimensional = false);
	~Camera();
	void UpdateCamera();
	void SetZoom(float amount);
	float GetZoom() { return zoom; };
	glm::mat4 GetProjectionMat() { return projectionMatrix; };
	glm::mat4 GetCameraMat() { return cameraMatrix; };
	Vector3 position;
	Vector3 rotation;
private:
	glm::mat4 cameraMatrix;
	glm::mat4 projectionMatrix;
	glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 right = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 offset = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 up = glm::vec3(0.0f,0.0f,0.0f);
	float zoom = 1.0f;
	bool _threedimensional = false;
};

