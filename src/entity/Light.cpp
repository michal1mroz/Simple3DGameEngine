#include "Light.h"

Light::Light(glm::vec3 position, glm::vec3 color)
    : position(position), color(color) {}

glm::vec3 Light::get_position(){
    return this->position;
}

glm::vec3 Light::get_color(){
    return this->color;
}

void Light::set_position(glm::vec3 newPosition){
    this->position = newPosition;
}

void Light::set_color(glm::vec3 newColor){
    this->color = newColor;
}
