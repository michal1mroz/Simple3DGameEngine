#include "StaticShader.h"

const std::string StaticShader::VERTEX_FILE = "src/shaders/vertexShader.txt";
const std::string StaticShader::FRAGMENT_FILE = "src/shaders/fragmentShader.txt";

StaticShader::StaticShader() : ShaderProgram(VERTEX_FILE, FRAGMENT_FILE) {
    bind_attributes();
    validate_program();
}

void StaticShader::bind_attributes(){
    bind_attribute(0, "position");
    bind_attribute(1, "textureCoords");
}

void StaticShader::get_all_uniform_locations(){
    this->locationTransformationMatrix = get_uniform_location("transformationMatrix");
}

void StaticShader::load_transformation_matrix(glm::mat4& mat){
    load_matrix(this->locationTransformationMatrix, mat);
}
