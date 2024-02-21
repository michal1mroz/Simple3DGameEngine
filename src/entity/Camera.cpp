#include "Camera.h"

Camera::Camera(DisplayManager display) : display(display){
    this->position = glm::vec3(0.f,0.f,0.f);
}

void Camera::move(){
    GLFWwindow* window = this->display.window;
    if(glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS){
        this->position.z -= 0.02f;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        this->position.z += 0.02f;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        this->position.x += 0.02f;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        this->position.x -= 0.02f;
    }
}

glm::vec3 Camera::get_position(){
    return this->position;
}

float Camera::get_pitch(){
    return this->pitch;
}

float Camera::get_roll(){
    return this->roll;
}

float Camera::get_yaw(){
    return this->yaw;
}
