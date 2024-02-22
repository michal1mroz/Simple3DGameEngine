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
#include "utils/OBJParser.h"

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

    Loader loader;
    Renderer renderer(dm, shader);

	RawModel model = OBJParser::load_obj_model("stall/stall.obj", loader);
	
	ModelTexture texture(loader.load_texture("stall/stallTexture.png"));
    TexturedModel texModel(model, texture);
    glm::vec3 position = glm::vec3(0.f,0.f,-50.f);
    Entity entity(texModel, position, 0.f, 0.f,0.f,1.f);

    Camera camera(dm);

    while(!glfwWindowShouldClose(dm.window)){
        //entity.set_position(0.f, 0.f,-0.01f);
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