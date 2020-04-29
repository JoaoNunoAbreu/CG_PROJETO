#include "headers/Translacao.h"
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
    
Translacao :: Translacao(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Translacao :: Translacao(float x1, float y1, float z1) {
    x = x1;
    y = y1;
    z = z1;
};

float Translacao :: getX(){return x;}
float Translacao :: getY(){return y;}
float Translacao :: getZ(){return z;}
void  Translacao :: setX(float x1){x = x1;}
void  Translacao :: setY(float y1){y = y1;}
void  Translacao :: setZ(float z1){z = z1;}
void  Translacao :: transform(){glTranslatef(x,y,z);}