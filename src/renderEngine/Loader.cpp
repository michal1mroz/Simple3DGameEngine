#include "Loader.h"

RawModel Loader::load_to_VAO(float positions[], int vertCount){
    unsigned int vaoID = create_VAO();
    store_data_in_attrib_list(0, positions, vertCount);
    unbind_VAO();

    return RawModel(vaoID,vertCount / 3);
}

void Loader::clean_up(){
    for(unsigned int vao: this->vaos){
        glDeleteVertexArrays(1, &vao);
    }
    for(unsigned int vbo: this->vbos){
        glDeleteBuffers(1,&vbo);
    }
    this->vaos.clear();
    this->vbos.clear();
}

unsigned int Loader::create_VAO(){
    unsigned int vaoID;
    glGenVertexArrays(1, &vaoID);
    this->vaos.push_back(vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}

void Loader::store_data_in_attrib_list(int attribNumber, float data[], int vertCount){
    unsigned int vboID;
    glGenBuffers(1, &vboID);
    this->vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), data, GL_STATIC_DRAW);
    glVertexAttribPointer(attribNumber, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
}

void Loader::unbind_VAO(){
    glBindVertexArray(0);
}
