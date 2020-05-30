#ifndef MODEL_H
#define MODEL_H

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
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct VBO {
    int size_vertices;
    GLuint vertices;
    int size_normals;
    GLuint normals;
    int size_tex;
    GLuint texCoords;
};

class Model {
private:
    int texFlag; // 0 -> color, 1 -> texture
    VBO v;
    GLuint texture;
    float ambient[4], diffuse[4], specular[4], emissive[4], shininess;
public:
    Model() {};
    ~Model() {};
    Model(int texFlag, VBO v, GLuint texture, float *amb, float *diff, float * spec, float *emiss, float shin);
    void drawModel();
};
#endif
