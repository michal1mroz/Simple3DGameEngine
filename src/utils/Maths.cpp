#include "Maths.h"

glm::mat4 Maths::create_transformation_matrix(glm::vec3& translation, float rx, float ry, float rz, float scale){
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), translation);
    glm::mat4 rotationMatrixX  = glm::rotate(glm::mat4(1.f), glm::radians(rx), glm::vec3(1.f,0.f,0.f));
    glm::mat4 rotationMatrixY  = glm::rotate(glm::mat4(1.f), glm::radians(ry), glm::vec3(0.f,1.f,0.f));
    glm::mat4 rotationMatrixZ  = glm::rotate(glm::mat4(1.f), glm::radians(rz), glm::vec3(0.f,0.f,1.f));
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.f), glm::vec3(scale,scale,scale));

    glm::mat4 transformationMatrix = translationMatrix * rotationMatrixX * rotationMatrixY * rotationMatrixZ * scaleMatrix;

    return transformationMatrix;
}

glm::mat4 Maths::create_view_matrix(Camera camera){
    glm::mat4 view(1.f);
    view = glm::rotate(view, glm::radians(camera.get_pitch()), glm::vec3(1.f,0.f,0.f));
    view = glm::rotate(view, glm::radians(camera.get_yaw()), glm::vec3(0.f,1.f,0.f));
    view = glm::rotate(view, glm::radians(camera.get_roll()), glm::vec3(0.f,0.f,1.f));
    view = glm::translate(view, -camera.get_position());
    return view;
}
