#include "RawModel.h"

RawModel::RawModel() : vaoID(0), vertexCount(-1) {}

RawModel::RawModel(unsigned int vaoID, int vertexCount) : vaoID(vaoID), vertexCount(vertexCount){}

unsigned int RawModel::get_vaoID()
{
    return this->vaoID;
}

int RawModel::get_vertexCount()
{
    return this->vertexCount;
}
