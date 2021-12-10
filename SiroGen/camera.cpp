#include "camera.h"

Camera::Camera(bool isThreeDimensional)
{
    if (isThreeDimensional)
    {
        projectionMatrix = glm::perspective(
            glm::radians(45.0f),
            16.0f / 9.0f,
            0.1f,
            1000.0f
        );
        offset = glm::vec3(0, 0, 0);
        glEnable(GL_CULL_FACE);
    }
    else
    {
        //glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
        projectionMatrix = glm::ortho(
            0.0f,
            1920.0f,
            -1080.0f,
            0.0f,
            0.1f,
            1000.0f
        );
        offset = glm::vec3(1920.0f /2, -1080.0f / 2, 0);
    }
    position.z = 650.0f;
    rotation = Vector3(0, 3.141592f, 0);
    up = glm::vec3(0, 1, 0);
    right = glm::vec3(1, 0, 0);
}

Camera::~Camera()
{

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

    _position = glm::vec3(position.x, position.y, position.z);

    std::cout << _position.x << ", " << _position.y << ", " << _position.z << ", " << std::endl;
    std::cout << direction.x << ", " << direction.y << ", " << direction.z << ", " << std::endl;
    std::cout << up.x << ", " << up.y << ", " << up.z << ", " << std::endl;

    cameraMatrix = glm::lookAt(
        _position -offset, //position
        _position -offset + direction, //direction
        up  //up
    );
}