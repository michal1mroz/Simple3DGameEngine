#ifndef RENDERER_H
#define RENDERER_H

#include "../entity/Entity.h"
#include "../shaders/StaticShader.h"
#include "../utils/Maths.h"
#include "DisplayManager.h"
#include "../textures/ModelTexture.h"

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtx/string_cast.hpp>

class Renderer{
public:
    Renderer(DisplayManager manager, StaticShader shader);
    void prepare();
    void render(Entity entity, StaticShader shader);
private:
    glm::mat4 projectionMatrix;
    static const float FOV;
    static const float NEAR_PLANE;
    static const float FAR_PLANE;
};

#endif //RENDERER_H