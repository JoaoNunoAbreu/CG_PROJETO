#ifndef Grupo_H
#define Grupo_H
#include "Transformacao.h"
#include "Model.h"
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#include <iterator>
#include <vector>
using namespace std;

class Grupo {
public:
    vector<Transformacao*> transformations;
    vector<Model*> models;
    vector<Grupo> childgroups;
public:
    Grupo() {};
    ~Grupo() {};
    void drawGroup(float tempo);
    void addTransformation(Transformacao* t);
    void addModel(Model* v);
    void addChilds(Grupo t);
};
#endif
