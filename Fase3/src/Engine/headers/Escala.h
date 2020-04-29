#ifndef ESCALA_H
#define ESCALA_H
#include "Transformacao.h"

class Escala : public Transformacao{

private: 
    float x;
    float y;
    float z;

public:
    Escala();
    Escala(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void transform();
};
#endif