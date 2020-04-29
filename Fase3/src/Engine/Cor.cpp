#include "headers/Cor.h"

#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Cor::Cor() {
    red = 0.0;
    green = 0.0;
    blue = 0.0;
}

Cor::Cor(float r, float g, float b) {
    red = r/255.0f;
    green = g/255.0f;
    blue = b/255.0f;
}

float Cor :: getR(){return red;}
float Cor :: getG(){return green;}
float Cor :: getB(){return blue;}
void  Cor :: setR(float r){red = r;}
void  Cor :: setG(float g){green = g;}
void  Cor :: setB(float b){blue = b;}
void  Cor :: transform(){glColor3f(red,green,blue);}
