#include "headers/Translacao.h"
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

    
Translacao :: Translacao(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
    time = 0.0;
    controlpoints.clear();
}

Translacao :: Translacao(float x1, float y1, float z1,float time1,vector<Ponto> cp) {
    x = x1;
    y = y1;
    z = z1;
    time = time1;
    controlpoints = cp;
};

float Translacao :: getX(){return x;}
float Translacao :: getY(){return y;}
float Translacao :: getZ(){return z;}
float Translacao :: getTime() { return time; };
void Translacao:: setTime(float time1) { time = time1; }
void  Translacao :: setX(float x1){x = x1;}
void  Translacao :: setY(float y1){y = y1;}
void  Translacao :: setZ(float z1){z = z1;}

void  Translacao :: transform(float tempo){
    if (controlpoints.empty())
        glTranslatef(x, y, z);
    
    else {
        float tm;

        float res[3];
        float deriv[3];

        renderCatmullRomCurve(controlpoints);

        static float Y[3] = { 0, 1, 0 };
        float Z[3];
        float x = (time * 1000); 
        tm = tempo / x;
        getGlobalCatmullRomPoint(tm, controlpoints, res, deriv);

        glTranslatef(res[0], res[1], res[2]);


        cross(deriv, Y, Z);
        cross(Z, deriv, Y);
        normalize(deriv);
        normalize(Z);
        normalize(Y);
        float m[16];
        buildRotMatrix(deriv, Y, Z, m);
        glMultMatrixf(m);
    }
    
}
