#ifndef TRANSLACAO_H
#define TRANSLACAO_H
#include "Transformacao.h"

class Translacao : public Transformacao{

private:
    float x;
    float y;
    float z;

public:
    Translacao();
    Translacao(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void transform();
};
#endif