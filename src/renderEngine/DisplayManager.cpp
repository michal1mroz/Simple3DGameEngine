#include "DisplayManager.h"

void errorCallback(int error, const char *description){
    std::cerr << "GLFW Error: "<<description<<std::endl;
}

void DisplayManager::create_display(){
    glfwSetErrorCallback(errorCallback);

    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW\n";
        exit(-1);
    }
    this->window = glfwCreateWindow(this->WIDTH, this->HEIGHT, "3D Game Engine", NULL, NULL);
    if(!this->window){
        std::cerr<< "Failed to create GLFW window\n";
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(this->window);
    glewInit();
}

void DisplayManager::update_display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void DisplayManager::clost_display(){
    glfwTerminate();
}
