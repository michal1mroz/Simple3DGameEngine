#include "MasterRenderer.h"

MasterRenderer::MasterRenderer(DisplayManager display) : display(display), shader(), renderer(display, shader) {
    this->entities = std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModelHash>();
}

void MasterRenderer::clean_up(){
    shader.clean_up();
}

void MasterRenderer::render(Light sun, Camera camera){
    renderer.prepare();
    shader.start();

    shader.load_light(sun);
    shader.load_view_matrix(camera);
    renderer.render(entities);
    shader.stop();
    entities.clear();
}

void MasterRenderer::process_entity(Entity entity){
    TexturedModel entityModel = entity.get_model();
    auto it = entities.find(entityModel);
    if(it != entities.end()){
        it->second.push_back(entity);
    }
    else{
        entities[entityModel] = std::vector<Entity>{entity};
    }

}
