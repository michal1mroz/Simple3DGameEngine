#include "Entity.h"

Entity::Entity(TexturedModel model, glm::vec3& vec, float rx, float ry, float rz, float scale) 
    : model(model), position(vec), rotX(rx), rotY(ry), rotZ(rz), scale(scale){}
    
TexturedModel Entity::get_model(){
    return this->model;
}

glm::vec3 Entity::get_position(){
    return this->position;
}

float Entity::get_rotation_x(){
    return this->rotX;
}

float Entity::get_rotation_y(){
    return this->rotY;
}

float Entity::get_rotation_z(){
    return this->rotZ;
}

float Entity::get_scale(){
    return this->scale;
}

void Entity::set_model(TexturedModel newModel){
    this->model = newModel;
}

void Entity::set_position(float dx, float dy, float dz){
    this->position.x += dx;
    this->position.y += dy;
    this->position.z += dz;
}

void Entity::set_rotation(float dx, float dy, float dz){
    this->rotX += dx;
    this->rotY += dy;
    this->rotZ += dz;
}
