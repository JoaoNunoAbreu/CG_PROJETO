#ifndef CatmullRomCurve_H
#define CatmullRomCurve_H

#include "../../include/Ponto.h"
#include <vector>
using namespace std;

void getCatmullRomPoint(float t, Ponto p0, Ponto p1, Ponto p2, Ponto p3, float* pos, float* deriv);
void getGlobalCatmullRomPoint(float gt, vector<Ponto>& controlPoints, float* pos, float* deriv);
void renderCatmullRomCurve(vector<Ponto>& controlPoints);
void buildRotMatrix(float* x, float* y, float* z, float* m);
void cross(float* a, float* b, float* res);
void normalize(float* a);

#endif