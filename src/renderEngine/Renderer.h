#ifndef RENDERER_H
#define RENDERER_H

#include "RawModel.h"

#include <GL/glew.h>
#include <iostream>

class Renderer{

public:
    void prepare();
    void render(RawModel model);
};

#endif //RENDERER_H