#ifndef STATICSHADER_H
#define STATICSHADER_H

#include "ShaderProgram.h"

class StaticShader : public ShaderProgram{
public:
    StaticShader();

protected:
    virtual void bind_attributes() override;

private:
    static const std::string VERTEX_FILE;
    static const std::string FRAGMENT_FILE;
    
};

#endif //STATICSHADER_H