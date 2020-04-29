#ifndef COR_H
#define COR_H
#include "Transformacao.h"


class Cor : public Transformacao{

private:
    float red;
    float green;
    float blue;

public:
    Cor();
    Cor(float r, float g, float b);
    float getR();
    float getG();
    float getB();
    void setR(float r);
    void setG(float g);
    void setB(float b);
    void transform();
};
#endif