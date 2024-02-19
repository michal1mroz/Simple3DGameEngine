#include "TexturedModel.h"

TexturedModel::TexturedModel(RawModel model, ModelTexture texture) :
    rawModel(model), texture(texture) {}

RawModel TexturedModel::get_model(){
    return this->rawModel;
}

ModelTexture TexturedModel::get_texture(){
    return this->texture;
}