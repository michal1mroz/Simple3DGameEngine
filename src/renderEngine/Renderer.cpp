#include "Renderer.h"

    // Definitions of the renderer constants 
const float Renderer::FOV = 45;
const float Renderer::NEAR_PLANE = 1;
const float Renderer::FAR_PLANE = 1000;

Renderer::Renderer(DisplayManager display, StaticShader shader){
    float aspectRatio = static_cast<float>(display.get_width() )/ display.get_height();
    this->projectionMatrix = glm::perspective(glm::radians(this->FOV), aspectRatio, this->NEAR_PLANE, this->FAR_PLANE);
    shader.start();
    shader.load_projection_matrix(projectionMatrix);
    shader.stop();
}

void Renderer::prepare(){
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0.3,0,1);
}

void Renderer::render(Entity entity, StaticShader shader){
    
    TexturedModel texturedModel = entity.get_model();
    RawModel model = texturedModel.get_model();
    glBindVertexArray(model.get_vaoID());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    auto position = entity.get_position(); // Trololololo
    glm::mat4 transformationMatrix = Maths::create_transformation_matrix(position, entity.get_rotation_x(),
        entity.get_rotation_y(), entity.get_rotation_z(), entity.get_scale());
    shader.load_transformation_matrix(transformationMatrix);

    ModelTexture texture = texturedModel.get_texture();
    shader.load_shine_variables(texture.get_shine_damper(), texture.get_reflectivity());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturedModel.get_texture().get_texture_id());
    glDrawElements(GL_TRIANGLES, model.get_vertexCount(), GL_UNSIGNED_INT, 0);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}
