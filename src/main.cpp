#include <iostream>

#include "renderEngine/DisplayManager.h"
#include "renderEngine/Renderer.h"
#include "renderEngine/Loader.h"
#include "renderEngine/MasterRenderer.h"

#include "models/RawModel.h"
#include "models/TexturedModel.h"

#include "shaders/StaticShader.h"

#include "textures/ModelTexture.h"

#include "entity/Entity.h"
#include "entity/Camera.h"
#include "entity/Light.h"

#include "utils/Maths.h"
#include "utils/OBJParser.h"

// Needed for stb_image to work
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <random>
#include <vector>

int main(){

    DisplayManager dm;
    dm.create_display();

    Loader loader;

	RawModel model = OBJParser::load_obj_model("place_holder/cube.obj", loader);
	
	ModelTexture texture(loader.load_texture("Solid_white.png"));
    TexturedModel texModel(model, texture);
	texture.set_shine_damper(10);
	texture.set_reflectivity(1);

    std::vector<Entity> entities;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(10, 200);
    for(int i = 0; i<100; i++){
        float x = distribution(gen);
        float y = distribution(gen);
        float z = distribution(gen);
        glm::vec3 position = glm::vec3(-x,-y,-z);
        Entity entity(texModel, position, 0.f, 0.f,0.f,1.f);
        entities.push_back(entity);
    }

    //glm::vec3 position = glm::vec3(0.f,0.f,-20.f);

    //Entity entity(texModel, position, 0.f, 0.f,0.f,1.f);
	Light light(glm::vec3(10,10,-10),glm::vec3(1,1,1));

    Camera camera(dm);

    MasterRenderer renderer(dm);

    while(!glfwWindowShouldClose(dm.window)){
        //entity.set_position(0.f, 0.f,-0.01f);
        camera.move();
        
        for(Entity entity : entities){
            renderer.process_entity(entity);
        }

        renderer.render(light, camera);
        dm.update_display();
    }

    renderer.clean_up();
    loader.clean_up();
    dm.close_display();
    return 0;
}