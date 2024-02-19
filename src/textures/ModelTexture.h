#ifndef MODELTEXTURE_H
#define MODELTEXTURE_H

#include <iostream>

class ModelTexture{
public:
    ModelTexture(unsigned int id);
    unsigned int get_texture_id();

private:
    unsigned int textureID;

};

#endif // MODELTEXTURE_H