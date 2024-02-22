#include "OBJParser.h"

RawModel OBJParser::load_obj_model(std::string fileName, Loader loader){    
    // Data loading part
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> textures;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec3> indices;

    std::string fullPath = "resources/"+fileName;

    std::ifstream file(fullPath);
    if(!file.is_open()){
        std::cerr << "Failed to open file: " <<fileName <<std::endl;
        exit(-1);
    }

    std::string line;
    
    while(std::getline(file, line)){
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v"){
            glm::vec3 vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            vertices.push_back(vertex);
        }
        else if (type == "vt"){
            glm::vec2 texCoord;
            iss >> texCoord.x >> texCoord.y;
            textures.push_back(texCoord);
        }
        else if (type == "vn"){
            glm::vec3 normal;
            iss >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        }
        else if (type == "f"){
            int v1, v2, v3;
            int vt1, vt2, vt3;
            int vn1, vn2, vn3;
            char slash;
            iss >> v1 >> slash >> vt1 >> slash >> vn1
                >> v2 >> slash >> vt2 >> slash >> vn2
                >> v3 >> slash >> vt3 >> slash >> vn3;

            glm::vec3 ind1, ind2, ind3;
            ind1.x = v1-1; ind1.y = vt1 - 1; ind1.z = vn1 - 1;
            ind2.x = v2-1; ind2.y = vt2 - 1; ind2.z = vn2 - 1;
            ind3.x = v3-1; ind3.y = vt3 - 1; ind3.z = vn3 - 1;
            indices.push_back(ind1);
            indices.push_back(ind2);
            indices.push_back(ind3);
        }
    }
    file.close();

    // Parsing into correct format
    float textureArray[2 * vertices.size()];
    float normalArray[3 * vertices.size()];

    // texture and normals setup
    for(glm::vec3 index : indices){
        glm::vec2 textureVector = textures.at(index.y);
        glm::vec3 normalVector = normals.at(index.z);
        textureArray[int(index.x) * 2] = textureVector.x;
        textureArray[int(index.x) * 2 + 1] = 1 - textureVector.y;
        normalArray[int(index.x) * 3] = normalVector.x;
        normalArray[int(index.x) * 3 + 1] = normalVector.y;
        normalArray[int(index.x) * 3 + 2] = normalVector.z;
    }

    float verticesArray[3 * vertices.size()];
    int indicesArray[indices.size()];

    int vertexPointer = 0;
    for(glm::vec3 vert : vertices){
        verticesArray[vertexPointer++] = vert.x;
        verticesArray[vertexPointer++] = vert.y;
        verticesArray[vertexPointer++] = vert.z;
    }
    
    for(int i = 0; i<indices.size(); i++){
        indicesArray[i] = indices.at(i).x;
    }
    int vertCount = sizeof(verticesArray) / sizeof(float);
    int texCount = sizeof(textureArray) / sizeof(float);
    int indexCount = sizeof(indicesArray) / sizeof(int);

    return loader.load_to_VAO(verticesArray, vertCount, indicesArray, indexCount, textureArray, texCount);
}