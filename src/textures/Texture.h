#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <stb/stb_image.h>
#include <GL/glew.h>

class Texture{
public:
    Texture(std::string path);
    unsigned int get_texture_ID();
private:
    int width, height, colorChanels;
    unsigned int textureID;
    unsigned char* bytes;

    void texture_generate_texture();
};

#endif // TEXTURE_H