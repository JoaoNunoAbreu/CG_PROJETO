#include "headers/Light.h"
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Light::Light(int type, int number, float *pos, float *amb, float *diff, float *spec, float *spot, float cutoff) {
    Light::type = type;
    Light::number = number;
    Light::position[0] = pos[0]; Light::position[1] = pos[1]; Light::position[2] = pos[2]; Light::position[3] = pos[3];
    Light::ambient[0] = amb[0]; Light::ambient[1] = amb[1]; Light::ambient[2] = amb[2]; Light::ambient[3] = amb[3];
    Light::diffuse[0] = diff[0]; Light::diffuse[1] = diff[1]; Light::diffuse[2] = diff[2]; Light::diffuse[3] = diff[3];
    Light::specular[0] = spec[0]; Light::specular[1] = spec[1]; Light::specular[2] = spec[2]; Light::specular[3] = spec[3];
    if (type == 2) {
        Light::spotDirection[0] = spot[0]; Light::spotDirection[1] = spot[1]; Light::spotDirection[2] = spot[2];
        Light::cutoff = cutoff;
    }
}
void Light::turnOn() {
    if (type == 1) position[3] = 0;
    else position[3] = 1;

    glLightfv(number + GL_LIGHT0, GL_POSITION, position);
    glLightfv(number + GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(number + GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(number + GL_LIGHT0, GL_SPECULAR, specular);

    if (type == 2) {
        glLightfv(number + GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);
        glLightf(number + GL_LIGHT0, GL_SPOT_CUTOFF, cutoff);
    }
}