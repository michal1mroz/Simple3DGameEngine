#include <iostream>
#include "renderEngine/DisplayManager.h"
#include "renderEngine/Renderer.h"
#include "renderEngine/Loader.h"
#include "renderEngine/RawModel.h"
#include "shaders/StaticShader.h"

int main(){

    DisplayManager dm;
    dm.create_display();

    StaticShader shader;

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
        shader.start();
        renderer.render(model);
        shader.stop();
        dm.update_display();        
    }

    shader.clean_up();
    loader.clean_up();
    dm.close_display();
    return 0;
}