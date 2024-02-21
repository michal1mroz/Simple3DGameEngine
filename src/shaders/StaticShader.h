#ifndef STATICSHADER_H
#define STATICSHADER_H

#include "ShaderProgram.h"
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

class StaticShader : public ShaderProgram{
public:
    StaticShader();
    void load_transformation_matrix(glm::mat4& mat);

protected:
    virtual void bind_attributes() override;
    virtual void get_all_uniform_locations() override;

private:
    static const std::string VERTEX_FILE;
    static const std::string FRAGMENT_FILE;

    int locationTransformationMatrix;    
};

#endif //STATICSHADER_H