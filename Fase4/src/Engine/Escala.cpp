#include "headers/Escala.h"
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Escala :: Escala(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Escala :: Escala(float x1, float y1, float z1) {
    x = x1;
    y = y1;
    z = z1;
};

float Escala :: getX(){ return x; }
float Escala :: getY(){ return y; }
float Escala :: getZ(){ return z; }
void  Escala :: setX(float x1){x = x1;}
void  Escala :: setY(float y1){y = y1;}
void  Escala :: setZ(float z1){z = z1;}
void  Escala :: transform(float tempo){glScalef(x,y,z);}