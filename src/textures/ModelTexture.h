#ifndef MODELTEXTURE_H
#define MODELTEXTURE_H

#include <iostream>

class ModelTexture{
public:
    ModelTexture();
    ModelTexture(unsigned int id);
    unsigned int get_texture_id();

    float get_shine_damper();
    float get_reflectivity();
    void set_shine_damper(float newDamper);
    void set_reflectivity(float newReflectivity);

private:
    unsigned int textureID;
    
    float shineDamper = 1;
    float reflectivity = 0;

};

#endif // MODELTEXTURE_H