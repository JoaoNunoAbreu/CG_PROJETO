#include "headers/Rotacao.h"
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Rotacao :: Rotacao() {
    angle = 0.0;
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Rotacao :: Rotacao(float a, float x1, float y1, float z1) {
    angle = a;
    x = x1;
    y = y1;
    z = z1;
}

float Rotacao :: getAngle(){ return angle;}
float Rotacao :: getX(){ return x; }
float Rotacao :: getY(){ return y; }
float Rotacao :: getZ(){ return z; }
void  Rotacao :: setAngle(float a){ angle = a; }
void  Rotacao :: setX(float x1){ x = x1;}
void  Rotacao :: setY(float y1){ y = y1;}
void  Rotacao :: setZ(float z1){ z = z1;}
void  Rotacao :: transform(){glRotatef(angle,x,y,z);}