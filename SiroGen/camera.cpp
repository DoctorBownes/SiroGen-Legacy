#include "camera.h"

Camera::Camera(bool isThreeDimensional)
{
    if (isThreeDimensional)
    {
        projectionMatrix = glm::perspective(
            glm::radians(45.0f),
            16.0f / 9.0f,
            0.1f,
            100.0f
        );
        offset = glm::vec3(0, 0, 0);
        glEnable(GL_CULL_FACE);
    }
    else
    {
        projectionMatrix = glm::ortho(
            0.0f,
            16.0f,
            9.0f,
            0.0f,
            0.1f,
            100.0f
        );
        offset = glm::vec3(16.0f /2, 9.0f / 2, 0);
    }
    position.z = 10.0f;
    rotation = Vector3(0, 3.141592f, 0);
    up = glm::vec3(0, 1, 0);
    right = glm::vec3(1, 0, 0);
}

Camera::~Camera()
{

}

void Camera::UpdateCamera()
{


    //double xpos, ypos;
    //glfwGetCursorPos(window, &xpos, &ypos);
    //glfwSetCursorPos(window, 1920 / 2, 1080 / 2);
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

    cameraMatrix = glm::lookAt(
        _position - offset, //position
        _position - offset + direction, //direction
        up  //up
    );
}