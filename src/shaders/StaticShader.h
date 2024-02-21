#ifndef STATICSHADER_H
#define STATICSHADER_H

#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include "ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

class StaticShader : public ShaderProgram{
public:
    StaticShader();
    void load_transformation_matrix(glm::mat4& mat);
    void load_projection_matrix(glm::mat4& mat);

protected:
    virtual void bind_attributes() override;
    virtual void get_all_uniform_locations() override;

private:
    static const std::string VERTEX_FILE;
    static const std::string FRAGMENT_FILE;

    int locationTransformationMatrix; 
    int locationProjectionMatrix;
};

#endif //STATICSHADER_H