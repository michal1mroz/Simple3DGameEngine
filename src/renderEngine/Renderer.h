#ifndef RENDERER_H
#define RENDERER_H

#include "../entity/Entity.h"
#include "../shaders/StaticShader.h"
#include "../utils/Maths.h"
#include "DisplayManager.h"
#include "../textures/ModelTexture.h"
#include "../models/TexturedModel.h"

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <unordered_map>
#include <vector>

class Renderer{
public:
    Renderer(DisplayManager manager, StaticShader shader);
    void prepare();
    void render(std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModelHash> entities);
    void render(Entity entity, StaticShader shader);
private:
    glm::mat4 projectionMatrix;
    StaticShader shader;
    DisplayManager display;
    static const float FOV;
    static const float NEAR_PLANE;
    static const float FAR_PLANE;

    void prepare_textured_model(TexturedModel model);
    void unbind_textured_model();
    void prepare_instance(Entity entity);
};

#endif //RENDERER_H