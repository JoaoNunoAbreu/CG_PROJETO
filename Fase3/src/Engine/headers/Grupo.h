#ifndef Grupo_H
#define Grupo_H
#include "Transformacao.h"
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

struct VBO {
    int size;
    GLuint vertices;
};


class Grupo {
public:
    vector<Transformacao*> transformations;
    vector<VBO> models;
    vector<Grupo> childgroups;
public:
    Grupo() {};
    ~Grupo() {};
    void drawGroup(float tempo);
    void draw(VBO models);
    void addTransformation(Transformacao* t);
    void addModel(VBO v);
    void addChilds(Grupo t);
};
#endif
