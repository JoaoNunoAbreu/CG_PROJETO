#ifndef LIGHT_H
#define LIGHT_H

class Light {
private:
    int type; //0->point, 1->direction, 2->spot
    int number;
    float position[4], ambient[4], diffuse[4], specular[4], spotDirection[4], cutoff;
public:
    Light();
    Light(int type, int number, float *pos, float *amb, float *diff, float *spec, float *spot, float cutoff);
    void turnOn();
};
#endif