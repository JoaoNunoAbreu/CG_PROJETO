#ifndef ROTACAO_H
#define ROTACAO_H
#include "Transformacao.h"

class Rotacao : public Transformacao{

private:
    float angle;
    float x;
    float y;
    float z;

public:
    Rotacao();
    Rotacao(float angle, float x, float y, float z);
    float getAngle();
    float getX();
    float getY();
    float getZ();
    void setAngle(float a);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void transform();
};
#endif