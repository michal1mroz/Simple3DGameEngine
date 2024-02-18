#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertexFile, std::string fragmentFile){
    this->vertexShaderID = load_shader(vertexFile, GL_VERTEX_SHADER);
    this->fragmentShaderID = load_shader(fragmentFile, GL_FRAGMENT_SHADER);

    this->programID = glCreateProgram();
    glAttachShader(this->programID, this->vertexShaderID);
    glAttachShader(this->programID, this->fragmentShaderID);
    glLinkProgram(this->programID);
    glValidateProgram(this->programID);
}


int ShaderProgram::load_shader(std::string file, int type){
    
    // std::ifstream ifs(file);
    // if(!ifs.is_open()){
    //     std::cerr<< "Unable to open shader file: " <<file<<std::endl;
    //     exit(-1);
    // }
    
    // std::stringstream shaderStream;
    // shaderStream << ifs.rdbuf();
    // std::string shaderSource = shaderStream.str();
    // if(shaderSource.empty()){
    //     std::cerr<< "File: "<<file<<" is empty"<<std::endl;
    //     exit(-1);
    // }
    // const char* shaderSourcePtr = shaderSource.c_str();

    std::ifstream ifs(file);
    std::string shaderSource(
        (std::istreambuf_iterator<char>(ifs)),
        std::istreambuf_iterator<char>()
    );    
    auto source = shaderSource.c_str();

    unsigned int shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &source, nullptr);
    glCompileShader(shaderID);

    int status;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS,&status);
    if(!status){
        char buffer[512];
        glGetShaderInfoLog(shaderID, 512, nullptr, buffer);
        std::cerr<<"Shader: "<<file<<"\ncompilation failed with status: "<<buffer<<std::endl;
        exit(-1);
    }
    return shaderID;
}

void ShaderProgram::start(){
    glUseProgram(this->programID);
}

void ShaderProgram::stop(){
    glUseProgram(0);
}

void ShaderProgram::clean_up(){
    stop();
    glDetachShader(this->programID, this->fragmentShaderID);
    glDetachShader(this->programID, this->vertexShaderID);
    glDeleteShader(this->vertexShaderID);
    glDeleteShader(this->fragmentShaderID);
    glDeleteProgram(this->programID);
}

void ShaderProgram::bind_attribute(int attribute, std::string varName){
    glBindAttribLocation(this->programID, attribute, varName.c_str());
}
