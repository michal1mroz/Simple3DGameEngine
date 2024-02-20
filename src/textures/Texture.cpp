#include "Texture.h"

Texture::Texture(std::string path){
    std::string fullPath = "resources/"+path;
    
    this->bytes = stbi_load(fullPath.c_str(),&this->width, &this->height, &this->colorChanels, 0);
    if(!bytes){
        std::cerr <<"Failed to load texture: " << path << std::endl;
    }

    glGenTextures(1, &this->textureID);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //GL_LINEAR 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    texture_generate_texture();

    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::get_texture_ID(){
    return this->textureID;
}

void Texture::texture_generate_texture(){
    switch(this->colorChanels){
        case 3: // .png without alpha channel
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->bytes);
            break;
        case 4: // .png with alpha channel
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->bytes);
            break;
    }
    glGenerateMipmap(GL_TEXTURE_2D);
}
