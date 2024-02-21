#ifndef MATHS_H
#define MATHS_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../entity/Camera.h"

class Maths{
public:
    static glm::mat4 create_transformation_matrix(glm::vec3& translation, float rx, float ry, float rz, float scale);
    static glm::mat4 create_view_matrix(Camera camera);
};

#endif // MATHS_H