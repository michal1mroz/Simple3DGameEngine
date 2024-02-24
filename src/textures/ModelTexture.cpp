#include "ModelTexture.h"

ModelTexture::ModelTexture() : textureID(0) {}

ModelTexture::ModelTexture(unsigned int id){
    this->textureID = id;
}

unsigned int ModelTexture::get_texture_id(){
    return this->textureID;
}

float ModelTexture::get_reflectivity(){
    return this->reflectivity;
}

float ModelTexture::get_shine_damper(){
    return this->shineDamper;
}

void ModelTexture::set_reflectivity(float newReflectivity){
    this->reflectivity = newReflectivity;
}

void ModelTexture::set_shine_damper(float newDamper){
    this->shineDamper = newDamper;
}
