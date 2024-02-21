#include <iostream>

#include "renderEngine/DisplayManager.h"
#include "renderEngine/Renderer.h"
#include "renderEngine/Loader.h"

#include "models/RawModel.h"
#include "models/TexturedModel.h"

#include "shaders/StaticShader.h"

#include "textures/ModelTexture.h"

#include "entity/Entity.h"

// Needed for stb_image to work
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <glm/glm.hpp>

#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/string_cast.hpp>

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

    float texCoords[] = {
        0.f,0.f,    //V0
        0.f,1.f,    //V1
        1.f,1.f,    //V2
        1.f,0.f     //V3
    };

    int vertCount = sizeof(vertices) / sizeof(float);
    int indCount = sizeof(indices) / sizeof(int);
    int texCount = sizeof(texCoords) / sizeof(float);

    Loader loader;
    Renderer renderer(dm, shader);

    RawModel model = loader.load_to_VAO(vertices, vertCount, indices, indCount, texCoords, texCount);
    ModelTexture texture(loader.load_texture("Important.png"));
    TexturedModel texModel(model, texture);
    glm::vec3 position = glm::vec3(0.f,0.f,-1.f);
    Entity entity(texModel, position, 0.f, 0.f,0.f,1.f);

    while(!glfwWindowShouldClose(dm.window)){
        //entity.set_position(0.f, 0.f,-0.01f);
        renderer.prepare();
        shader.start();
        renderer.render(entity, shader);
        std::cout << glm::to_string(entity.get_position()) << std::endl;
        shader.stop();
        dm.update_display();
    }

    shader.clean_up();
    loader.clean_up();
    dm.close_display();
    return 0;
}