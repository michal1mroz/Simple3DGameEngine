#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

#include "../renderEngine/DisplayManager.h"

class Camera{
public:
    Camera(DisplayManager display);
    glm::vec3 get_position();
    float get_pitch();
    float get_yaw();
    float get_roll();
    void move();

private:
    glm::vec3 position;
    float pitch = 0;
    float yaw = 1;
    float roll = 0;
    DisplayManager display;
};

#endif // CAMERA_H