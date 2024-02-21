#include <iostream>

#include "renderEngine/DisplayManager.h"
#include "renderEngine/Renderer.h"
#include "renderEngine/Loader.h"

#include "models/RawModel.h"
#include "models/TexturedModel.h"

#include "shaders/StaticShader.h"

#include "textures/ModelTexture.h"

#include "entity/Entity.h"
#include "entity/Camera.h"

#include "utils/Maths.h"

// Needed for stb_image to work
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTA
#include <glm/gtx/string_cast.hpp>

int main(){

    DisplayManager dm;
    dm.create_display();

    StaticShader shader;

    /*
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
    */
    
    float vertices[] = {
        -0.5f,0.5f,-0.5f,	
		-0.5f,-0.5f,-0.5f,	
		0.5f,-0.5f,-0.5f,	
		0.5f,0.5f,-0.5f,		
		
		-0.5f,0.5f,0.5f,	
		-0.5f,-0.5f,0.5f,	
		0.5f,-0.5f,0.5f,	
		0.5f,0.5f,0.5f,
				
		0.5f,0.5f,-0.5f,	
		0.5f,-0.5f,-0.5f,	
		0.5f,-0.5f,0.5f,	
		0.5f,0.5f,0.5f,
				
		-0.5f,0.5f,-0.5f,	
		-0.5f,-0.5f,-0.5f,	
		-0.5f,-0.5f,0.5f,	
		-0.5f,0.5f,0.5f,
				
		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,
				
		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f
    };

    float texCoords[] = {
        0,0,
		0,1,
		1,1,
		1,0,			
		0,0,
		0,1,
		1,1,
		1,0,			
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0       
    };

    int indices[] = {
        0,1,3,	
		3,1,2,	
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,	
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22
    };

    int vertCount = sizeof(vertices) / sizeof(float);
    int indCount = sizeof(indices) / sizeof(int);
    int texCount = sizeof(texCoords) / sizeof(float);

    Loader loader;
    Renderer renderer(dm, shader);

    RawModel model = loader.load_to_VAO(vertices, vertCount, indices, indCount, texCoords, texCount);
    ModelTexture texture(loader.load_texture("pop_cat.png"));
    TexturedModel texModel(model, texture);
    glm::vec3 position = glm::vec3(0.f,0.f,-2.f);
    Entity entity(texModel, position, 0.f, 0.f,0.f,1.f);

    Camera camera(dm);

    while(!glfwWindowShouldClose(dm.window)){
        entity.set_position(0.f, 0.001f,-0.01f);
        camera.move();
        entity.set_rotation(1,1,1);
        renderer.prepare();
        shader.start();
        shader.load_view_matrix(camera);
        renderer.render(entity, shader);
        shader.stop();
        dm.update_display();
    }

    shader.clean_up();
    loader.clean_up();
    dm.close_display();
    return 0;
}