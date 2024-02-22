#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

    /*
        This class should be treated as a pure abstract one.
        While it will work the idea of the project architecture comes from 
        java where you can define pure abstract classes.
        In the implementation you need to call the bind_attributes() implementation
        and then validate_program() method.
    */

class ShaderProgram{
public:
    ShaderProgram(std::string vertexFile, std::string fragmentFile);
    void start();
    void stop();
    void clean_up();
    int get_programID();

protected:
    virtual void bind_attributes() = 0;
    void bind_attribute(int attribute, std::string varName);
    void validate_program();

    int get_uniform_location(std::string uniformName);
    virtual void get_all_uniform_locations() = 0;

    void load_float(int location, float val);
    void load_vector(int location,const glm::vec3& vect);
    void load_boolean(int location, bool val);
    void load_matrix(int location, glm::mat4& mat);

private:
    int programID;
    int vertexShaderID;
    int fragmentShaderID;

    int load_shader(std::string file, int type);
};

#endif //SHADERPROGRAM_H