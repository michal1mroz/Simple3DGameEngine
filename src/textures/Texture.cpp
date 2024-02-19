#include "Texture.h"

Texture::Texture(std::string path){
    std::string fullPath = "resources/"+path;
    
    this->bytes = stbi_load(fullPath.c_str(),&this->width, &this->height, &this->colorChanels, 0);
    if(!bytes){
        std::cerr <<"Failed to load texture: " << path << std::endl;
    }
    
    glGenTextures(1, &this->textureID);

    glBindTexture(GL_TEXTURE_2D, this->textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //GL_LINEAR

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height,0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::get_texture_ID(){
    return this->textureID;
}
