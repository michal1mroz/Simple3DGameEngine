#include "Renderer.h"

    // Definitions of the renderer constants 
const float Renderer::FOV = 45;
const float Renderer::NEAR_PLANE = 1;
const float Renderer::FAR_PLANE = 1000;

Renderer::Renderer(DisplayManager display, StaticShader shader) : shader(shader), display(display){
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

void Renderer::render(std::unordered_map<TexturedModel, std::vector<Entity>, TexturedModelHash> entities){
    for(auto& model : entities){
        prepare_textured_model(model.first);
        std::vector<Entity> batch = model.second;
        for(Entity entity : batch){
            prepare_instance(entity);
            glDrawElements(GL_TRIANGLES, model.first.get_model().get_vertexCount(),
                    GL_UNSIGNED_INT, 0);
        }
        unbind_textured_model();
    }
}

void Renderer::prepare_textured_model(TexturedModel model){
    RawModel rawModel = model.get_model();
    glBindVertexArray(rawModel.get_vaoID());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    ModelTexture texture = model.get_texture();
    shader.load_shine_variables(texture.get_shine_damper(), texture.get_reflectivity());
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture.get_texture_id());
}

void Renderer::unbind_textured_model(){
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

void Renderer::prepare_instance(Entity entity){
    auto position = entity.get_position(); // Trololololo
    glm::mat4 transformationMatrix = Maths::create_transformation_matrix(position, entity.get_rotation_x(),
        entity.get_rotation_y(), entity.get_rotation_z(), entity.get_scale());
    shader.load_transformation_matrix(transformationMatrix);
}
