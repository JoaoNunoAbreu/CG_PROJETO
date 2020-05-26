#ifndef BEZIERPATCH_H
#define BEZIERPATCH_H

#include "../../Common/Ponto.h"
#include "../../Common/Normal.h"
#include <vector>
#include <math.h>
using namespace std;

Normal normalBezier(vector<Ponto>& patch_points,float u,float v);
float* derivateUBezier(vector<Ponto>& patch_points, float u, float v,float* vector);
float* derivateVBezier(vector<Ponto>& patch_points, float u, float v,float* vector);
Ponto generateBezierPoint(vector<Ponto>& patch_points, float u, float v);

#endif