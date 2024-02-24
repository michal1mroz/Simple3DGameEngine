#ifndef MASTERRENDERER_H
#define MASTERRENDERER_H

#include "Renderer.h"
#include "../entity/Entity.h"
#include "../entity/Light.h"
#include "../entity/Camera.h"
#include "../models/TexturedModel.h"
#include "../shaders/StaticShader.h"
#include "DisplayManager.h"

#include <unordered_map>
#include <vector>
#include <iostream>

class MasterRenderer{
public:
    MasterRenderer(DisplayManager display);
    void clean_up();
    void render(Light sun, Camera camera);
    void process_entity(Entity entity);
private:
    DisplayManager display;
    StaticShader shader;
    Renderer renderer;

    std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModelHash> entities; 
};

#endif // MASTERRENDERER_H