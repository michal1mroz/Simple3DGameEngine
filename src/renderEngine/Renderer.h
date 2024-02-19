#ifndef RENDERER_H
#define RENDERER_H

#include "../models/TexturedModel.h"


#include <GL/glew.h>
#include <iostream>

class Renderer{

public:
    void prepare();
    void render(TexturedModel model);
};

#endif //RENDERER_H