#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>

class Light{
public:
    Light(glm::vec3 position, glm::vec3 color);
    
    glm::vec3 get_position();
    glm::vec3 get_color();

    void set_position(glm::vec3 newPosition);
    void set_color(glm::vec3 newColor);
private:
    glm::vec3 position;
    glm::vec3 color;

};

#endif // LIGHT_H