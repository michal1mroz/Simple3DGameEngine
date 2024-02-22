#ifndef OBJPARSER_H
#define OBJPARSER_H

#include "../models/RawModel.h"
#include "../renderEngine/Loader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <glm/glm.hpp>

class OBJParser{
public:
    static RawModel load_obj_model(std::string fileName, Loader loader); 
};  

#endif // OBJPARSER