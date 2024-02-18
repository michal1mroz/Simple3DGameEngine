#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class DisplayManager{
private:
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;

public:
    GLFWwindow* window = nullptr;

    void create_display();
    void update_display();
    void close_display();
};

#endif //DISPLAYMANAGER_H