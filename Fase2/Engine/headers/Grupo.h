#ifndef Grupo_H
#define Grupo_H
#include "Transformacao.h"
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iterator>
#include <vector>
using namespace std;

struct Ponto {
    float x;
    float y;
    float z;
};

class Grupo {
public:
    vector<Transformacao*> transformations;
    vector<vector<Ponto>> models;
    vector<Grupo> childgroups;
public:
    Grupo() {};
    ~Grupo() {};
    void drawGroup();
    void draw(vector<Ponto> models);
    void addTransformation(Transformacao* t);
    void addModel(vector<Ponto> t);
    void addChilds(Grupo t);
};
#endif
