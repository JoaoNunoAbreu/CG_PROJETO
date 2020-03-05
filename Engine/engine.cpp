#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;
using namespace std;

float radius = 5;
float alpha = 0;
float beta = 0;

void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float px = radius * cos(beta) * sin(alpha);
    float py = radius * sin(beta);
    float pz = radius * cos(beta) * cos(alpha);
    
    // set the camera
    glLoadIdentity();
    gluLookAt(px, py, pz,
        0.0, 0.0, 0.0,
        0.0f, 1.0f, 0.0f);
    
    // End of frame
    glutSwapBuffers();
}

void processSpecialKeys(int key, int xx, int yy) {
    switch (key) {
    case GLUT_KEY_UP:
        if (beta < (M_PI / 2))
            beta += (float)M_PI / 50;
        break;
    case GLUT_KEY_DOWN:
        if (beta > -(M_PI / 2))
            beta -= (float)M_PI / 50;
        break;
    case GLUT_KEY_LEFT:
        alpha -= (float)M_PI / 50;
        break;
    case GLUT_KEY_RIGHT:
        alpha += (float)M_PI / 50;
        break;
    default:
        break;
    }

}

void readXML(string fich) {
    
    XMLDocument doc;
    XMLElement *root;

    if (!(doc.LoadFile(fich.c_str()))) {
        root = doc.FirstChildElement();
        for (XMLElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
            string ficheiro = elem->Attribute("file");
            cout << "Ficheiro:" << ficheiro << "lido com sucesso" << endl;
            //readFile(ficheiro);
        }
    } else {
        cout << "Ficheiro XML não foi encontrado" << endl;
    }
}

int main(){
    
    readXML("config.xml");
    
    return 1;
}
