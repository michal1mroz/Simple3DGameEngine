#include "Loader.h"

RawModel Loader::load_to_VAO(float positions[], int vertCount, int indices[], int indicesCount, float textureCoordinates[], int textureCount){
    unsigned int vaoID = create_VAO();
    bind_indices_buffer(indices, indicesCount);
    store_data_in_attrib_list(0, positions, vertCount, 3);
    store_data_in_attrib_list(1, textureCoordinates, textureCount, 2);

    unbind_VAO();

    return RawModel(vaoID, indicesCount);
}

void Loader::clean_up(){
    for(unsigned int vao: this->vaos){
        glDeleteVertexArrays(1, &vao);
    }
    for(unsigned int vbo: this->vbos){
        glDeleteBuffers(1,&vbo);
    }
    for(unsigned int tex: this->textures){
        glDeleteTextures(1, &tex);
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

void Loader::store_data_in_attrib_list(int attribNumber, float data[], int dataCount, int coordSize){
    unsigned int vboID;
    glGenBuffers(1, &vboID);
    this->vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, dataCount * sizeof(float), data, GL_STATIC_DRAW);
    glVertexAttribPointer(attribNumber, coordSize, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
}

void Loader::unbind_VAO(){
    glBindVertexArray(0);
}

void Loader::bind_indices_buffer(int indices[], int indicesCount){
    unsigned int vboID;
    glGenBuffers(1, &vboID);
    this->vbos.push_back(vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(int), indices, GL_STATIC_DRAW);
}

unsigned int Loader::load_texture(std::string fileName){
    // std::string fullPath = "resources/"+fileName;
    // int imgWidth, imgHeight, numColCh;
    // unsigned char* bytes = stbi_load(fullPath.c_str(),&imgWidth, &imgHeight, &numColCh, 0);
    // unsigned int texture;
    // glGenTextures(1, &texture);
    // this->textures.push_back(texture);
    // return texture;
    Texture texture(fileName);
    textures.push_back(texture.get_texture_ID());
    return texture.get_texture_ID();
}
