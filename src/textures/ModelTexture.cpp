#include "ModelTexture.h"

ModelTexture::ModelTexture(unsigned int id){
    this->textureID = id;
}

unsigned int ModelTexture::get_texture_id(){
    return this->textureID;
}
