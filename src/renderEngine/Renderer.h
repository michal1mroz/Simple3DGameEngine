#ifndef RENDERER_H
#define RENDERER_H

#include "../entity/Entity.h"
#include "../shaders/StaticShader.h"
#include "../utils/Maths.h"

#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>

class Renderer{

public:
    void prepare();
    void render(Entity entity, StaticShader shader);
};

#endif //RENDERER_H