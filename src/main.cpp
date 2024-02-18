#include <iostream>
#include "renderEngine/DisplayManager.h"
#include "renderEngine/Renderer.h"
#include "renderEngine/Loader.h"
#include "renderEngine/RawModel.h"

int main(){

    DisplayManager dm;
    dm.create_display();


    float vertices[] = {
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,

        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
    };


    Loader loader;
    Renderer renderer;

    RawModel model = loader.load_to_VAO(vertices, sizeof(vertices) / sizeof(float));
    std::cout <<model.get_vertexCount();
    while(!glfwWindowShouldClose(dm.window)){
        renderer.prepare();
        renderer.render(model);
        dm.update_display();        
    }

    loader.clean_up();
    dm.close_display();
    return 0;
}