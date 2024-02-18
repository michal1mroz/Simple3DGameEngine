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
        0.5f, 0.5f, 0.0f
    };

    int indices[] = {
        0,1,3,
        3,1,2
    };

    int vertCount = sizeof(vertices) / sizeof(float);
    int indCount = sizeof(indices) / sizeof(int);

    Loader loader;
    Renderer renderer;

    RawModel model = loader.load_to_VAO(vertices, vertCount, indices, indCount);
    while(!glfwWindowShouldClose(dm.window)){
        renderer.prepare();
        renderer.render(model);
        dm.update_display();        
    }

    loader.clean_up();
    dm.close_display();
    return 0;
}