#include "camera.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Camera::Camera(bool isThreeDimensional)
{
    _threedimensional = isThreeDimensional;
    if (isThreeDimensional)
    {
        SetZoom(45.0f);
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        SetZoom(1.0f);
        glDisable(GL_DEPTH_TEST);
    }
    glDepthFunc(GL_LESS);
   // position.z = 650.0f;
    rotation = Vector2(0, 3.141592f);
    up = glm::vec3(0, 1, 0);
    right = glm::vec3(1, 0, 0);
}

Camera::~Camera()
{

}

void Camera::SetZoom(float amount)
{
    if (_threedimensional)
    {
        projectionMatrix = glm::perspective(
            glm::radians(amount),
            16.0f / 9.0f,
            0.1f,
            1000.0f
        );
        offset = glm::vec3(0, 0, 0);
    }
    else
    {
        projectionMatrix = glm::ortho(
            0.0f,
            1920.0f / amount,
            -1080.0f / amount,
            0.0f,
            0.1f,
            1000.0f
        );
        offset = glm::vec3((1920.0f / amount) / 2, (-1080.0f / amount) / 2, 0);
    }
}

void Camera::UpdateCamera()
{
    direction = glm::vec3(
        cos(rotation.y) * sin(rotation.x),
        sin(rotation.y),
        cos(rotation.y) * cos(rotation.x)
    );

    right = glm::vec3(
        sin(rotation.x + 3.141592f / 2),
        0,
        cos(rotation.x + 3.141592f / 2)
    );
    up = glm::cross(right, direction);

    _position = glm::vec3(position.x, position.y, 1.0f);

    //std::cout << _position.x << ", " << _position.y << ", " << _position.z << ", " << std::endl;
    //std::cout << direction.x << ", " << direction.y << ", " << direction.z << ", " << std::endl;
    //std::cout << up.x << ", " << up.y << ", " << up.z << ", " << std::endl;

    cameraMatrix = glm::lookAt(
        _position -offset, //position
        _position -offset + direction, //direction
        up  //up
    );
}