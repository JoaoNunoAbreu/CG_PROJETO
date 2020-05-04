#include "headers/CatmullRomCurve.h"
#include <stdlib.h>
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <direct.h>
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#include <iostream>


void getCatmullRomPoint(float t, Ponto p0, Ponto p1, Ponto p2, Ponto p3, float* pos, float* deriv) {

    // catmull-rom matrix
    float m[4][4] = { {-0.5f,  1.5f, -1.5f,  0.5f},
                        { 1.0f, -2.5f,  2.0f, -0.5f},
                        {-0.5f,  0.0f,  0.5f,  0.0f},
                        { 0.0f,  1.0f,  0.0f,  0.0f} };

    float res_aux[4];
    float tv[4] = { t * t * t, t * t, t, 1 };
    float tvl[4] = { 3 * t * t, 2 * t, 1, 0 };

    res_aux[0] = tv[0] * m[0][0] + tv[1] * m[1][0] + tv[2] * m[2][0] + tv[3] * m[3][0];
    res_aux[1] = tv[0] * m[0][1] + tv[1] * m[1][1] + tv[2] * m[2][1] + tv[3] * m[3][1];
    res_aux[2] = tv[0] * m[0][2] + tv[1] * m[1][2] + tv[2] * m[2][2] + tv[3] * m[3][2];
    res_aux[3] = tv[0] * m[0][3] + tv[1] * m[1][3] + tv[2] * m[2][3] + tv[3] * m[3][3];

    pos[0] = res_aux[0] * p0.x + res_aux[1] * p1.x + res_aux[2] * p2.x + res_aux[3] * p3.x;
    pos[1] = res_aux[0] * p0.y + res_aux[1] * p1.y + res_aux[2] * p2.y + res_aux[3] * p3.y;
    pos[2] = res_aux[0] * p0.z + res_aux[1] * p1.z + res_aux[2] * p2.z + res_aux[3] * p3.z;

    res_aux[0] = tvl[0] * m[0][0] + tvl[1] * m[1][0] + tvl[2] * m[2][0];
    res_aux[1] = tvl[0] * m[0][1] + tvl[1] * m[1][1] + tvl[2] * m[2][1];
    res_aux[2] = tvl[0] * m[0][2] + tvl[1] * m[1][2] + tvl[2] * m[2][2];
    res_aux[3] = tvl[0] * m[0][3] + tvl[1] * m[1][3] + tvl[2] * m[2][3];

    deriv[0] = res_aux[0] * p0.x + res_aux[1] * p1.x + res_aux[2] * p2.x + res_aux[3] * p3.x;
    deriv[1] = res_aux[0] * p0.y + res_aux[1] * p1.y + res_aux[2] * p2.y + res_aux[3] * p3.y;
    deriv[2] = res_aux[0] * p0.z + res_aux[1] * p1.z + res_aux[2] * p2.z + res_aux[3] * p3.z;
}

void getGlobalCatmullRomPoint(float gt, vector<Ponto>& controlPoints, float* pos, float* deriv) {

    float t = gt * controlPoints.size(); // this is the real global t
    int index = floor(t);  // which segment
    t = t - index; // where within  the segment

    // indices store the points
    int indices[4];
    indices[0] = (index + controlPoints.size() - 1) % controlPoints.size();
    indices[1] = (indices[0] + 1) % controlPoints.size();
    indices[2] = (indices[1] + 1) % controlPoints.size();
    indices[3] = (indices[2] + 1) % controlPoints.size();

    getCatmullRomPoint(t, controlPoints.at(indices[0]), controlPoints.at(indices[1]), controlPoints.at(indices[2]), controlPoints.at(indices[3]), pos, deriv);
}

void buildRotMatrix(float* x, float* y, float* z, float* m) {

    m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
    m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
    m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
    m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}

void cross(float* a, float* b, float* res) {

    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(float* a) {

    float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0] / l;
    a[1] = a[1] / l;
    a[2] = a[2] / l;
}

void renderCatmullRomCurve(vector<Ponto>& controlPoints) {

    // draw curve using line segments with GL_LINE_LOOP
   glColor3f(1, 1, 1);
   glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 100; i++) {
        float pos[3];
        float deriv[3];
        getGlobalCatmullRomPoint(i / 100.f, controlPoints ,pos , deriv);
        glVertex3f(pos[0], pos[1], pos[2]);
    }
       glEnd();
}
