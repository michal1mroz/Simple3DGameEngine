#include "StaticShader.h"

const std::string StaticShader::VERTEX_FILE = "src/shaders/vertexShader.txt";
const std::string StaticShader::FRAGMENT_FILE = "src/shaders/fragmentShader.txt";

StaticShader::StaticShader() : ShaderProgram(VERTEX_FILE, FRAGMENT_FILE){
    bind_attributes();
    validate_program();
    get_all_uniform_locations();
}

void StaticShader::bind_attributes(){
    bind_attribute(0, "position");
    bind_attribute(1, "textureCoords");
    bind_attribute(2, "normal");
}

void StaticShader::get_all_uniform_locations(){
    // stuff for transformations
    this->locationTransformationMatrix = get_uniform_location("transformationMatrix");
    this->locationProjectionMatrix = get_uniform_location("projectionMatrix");
    this->locationViewMatrix = get_uniform_location("viewMatrix");
    
    // lighting variables
    this->locationLightPosition = get_uniform_location("lightPosition");
    this->locationLightColor = get_uniform_location("lightColor");
    this->loactionReflectivity = get_uniform_location("reflectivity");
    this->locationShineDamper = get_uniform_location("shineDamper");
}

void StaticShader::load_transformation_matrix(glm::mat4& mat){
    load_matrix(this->locationTransformationMatrix, mat);
}

void StaticShader::load_projection_matrix(glm::mat4& mat){
    load_matrix(this->locationProjectionMatrix, mat);
}

void StaticShader::load_view_matrix(Camera camera){
    glm::mat4 view = Maths::create_view_matrix(camera);
    load_matrix(this->locationViewMatrix, view);
}

void StaticShader::load_light(Light light){
    load_vector(this->locationLightPosition, light.get_position());
    load_vector(this->locationLightColor, light.get_color());
}

void StaticShader::load_shine_variables(float damper, float reflectivity){
    load_float(this->locationShineDamper, damper);
    load_float(this->loactionReflectivity, reflectivity);
}
