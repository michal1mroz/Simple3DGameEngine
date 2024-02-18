#ifndef LOADER_H
#define LOADER_H

#include "RawModel.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

class Loader{
private:
    std::vector<unsigned int> vaos;
    std::vector<unsigned int> vbos; 

    unsigned int create_VAO();
    void store_data_in_attrib_list(int attribNumber, float data[], int vertCount);
    void unbind_VAO();
public:
    RawModel load_to_VAO(float positions[], int vertCount);
    void clean_up();
};

#endif // LOADER_H