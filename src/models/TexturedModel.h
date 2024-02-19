#ifndef TEXTUREDMODEL_H
#define TEXTUREDMODEL_H

#include "RawModel.h"
#include "../textures/ModelTexture.h"

class TexturedModel{
public:
    TexturedModel(RawModel model, ModelTexture texture);
    RawModel get_model();
    ModelTexture get_texture();
private:
    RawModel rawModel;
    ModelTexture texture;
};

#endif // TEXTUREDMODEL_H