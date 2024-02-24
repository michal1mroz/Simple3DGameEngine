#ifndef TEXTUREDMODEL_H
#define TEXTUREDMODEL_H

#include "RawModel.h"
#include "../textures/ModelTexture.h"
#include "../utils/OBJParser.h"
#include "../renderEngine/Loader.h"

#include <unordered_map>
#include <functional>
#include <iostream>

class TexturedModel{
public:
    TexturedModel();
    TexturedModel(RawModel model, ModelTexture texture);
    RawModel get_model() const;
    ModelTexture get_texture() const;

    bool operator==(const TexturedModel& other) const;
    //friend struct std::hash<TexturedModel>;

private:
    RawModel rawModel;
    ModelTexture texture;
};

class TexturedModelHash{
public:
    size_t operator()(const TexturedModel& model) const;
};

#endif // TEXTUREDMODEL_H