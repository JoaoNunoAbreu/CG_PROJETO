#ifndef TRANSLACAO_H
#define TRANSLACAO_H
#include "Transformacao.h"
#include "../../include/Ponto.h"
#include "headers/CatmullRomCurve.h"
#include <vector>

using namespace std;

class Translacao : public Transformacao{

private:
    float x;
    float y;
    float z;
    float time;
    std::vector<Ponto> controlpoints;

public:
    Translacao();
    Translacao(float x, float y, float z, float time, vector<Ponto> cp);
    float getX();
    float getY();
    float getZ();
    float getTime();
    void setTime(float time1);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void transform(float tempo);
};
#endif