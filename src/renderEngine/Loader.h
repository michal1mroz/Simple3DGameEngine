#ifndef LOADER_H
#define LOADER_H

#include <stb/stb_image.h>
#include "../models/RawModel.h"
#include "../textures/Texture.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

class Loader{
private:
    std::vector<unsigned int> vaos;
    std::vector<unsigned int> vbos; 
    std::vector<unsigned int> textures;

    unsigned int create_VAO();
    void store_data_in_attrib_list(int attribNumber, float data[], int dataCount, int coordSize);
    void unbind_VAO();
    void bind_indices_buffer(int indices[], int indicesCount);

public:
    RawModel load_to_VAO(float positions[], int vertCount, int indices[],
        int indicesCount, float textureCoordinates[], int textureCount,
        float normals[], int normalsCount);
    unsigned int load_texture(std::string fileName);
    void clean_up();
};

#endif // LOADER_H