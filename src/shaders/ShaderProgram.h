#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

class ShaderProgram{
public:
    ShaderProgram(std::string vertexFile, std::string fragmentFile);
    void start();
    void stop();
    void clean_up();

protected:
    virtual void bind_attributes() = 0;
    void bind_attribute(int attribute, std::string varName);

private:
    int programID;
    int vertexShaderID;
    int fragmentShaderID;

    int load_shader(std::string file, int type);
};

#endif //SHADERPROGRAM_H