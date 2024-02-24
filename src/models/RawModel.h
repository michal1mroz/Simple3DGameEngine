#ifndef RAWMODEL_H
#define RAWMODEL_H

class RawModel{
private:
    unsigned int vaoID;
    int vertexCount;
public:
    RawModel();
    RawModel(unsigned int vaoID, int vertexCount);

    unsigned int get_vaoID();
    int get_vertexCount();
};

#endif //RAWMODEL_H