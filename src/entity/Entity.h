#ifndef ENTITY_H
#define ENTITY_H

#include "../models/TexturedModel.h"
#include "../renderEngine/Loader.h"
#include "../models/RawModel.h"
#include "../textures/ModelTexture.h"

#include <glm/glm.hpp>

class Entity{
public:
    Entity();
    Entity(TexturedModel model, glm::vec3& position, float rx, float ry, float rz, float scale);

    TexturedModel get_model();
    glm::vec3 get_position();
    float get_rotation_x();
    float get_rotation_y();
    float get_rotation_z();
    float get_scale();

    void set_model(TexturedModel newModel);
    void set_position(float dx, float dy, float dz);
    void set_rotation(float dx, float dy, float dz);

private:
    TexturedModel model;
    float rotX, rotY, rotZ, scale;
    glm::vec3 position;
};

#endif // ENTITY_H