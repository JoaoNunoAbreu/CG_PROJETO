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
#include <map>
#include <iterator>
#include <algorithm>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

float r = 20;           // distância entre a câmara e o ponto de referência.
float alpha = M_PI/4;
float beta = M_PI/4;

struct Ponto {
    float x;
    float y;
    float z;
};

vector<Ponto> pontos;              // pontos de uma primitiva.
map<int,vector<Ponto>> primitivas; // id das primitivas e os seus correspondentes vértices.

void draw(){
    
    glBegin(GL_LINES);
        // X axis in red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(100.0f, 0.0f, 0.0f);
        // Y Axis in Green
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 100.0f, 0.0f);
        // Z Axis in Orange
        glColor3f(1, 0.5, 0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
    
    
    
    glBegin(GL_TRIANGLES);
    map<int,vector<Ponto>>::iterator it = primitivas.begin();
    
    int num_primitivas = primitivas.size();
    int n = 0; // para cada primitiva ter a sua cor
    
    while (it != primitivas.end()){
        // int inteiro = it->first; Pode ser útil ????????

        vector<Ponto> pontos = it->second;
    
        for(int i = 0; i < pontos.size(); i++){
            glColor3f((1./num_primitivas)*n, 1, 1);
            glVertex3f(pontos[i].x, pontos[i].y, pontos[i].z);
        }
        it++;
        n++;
    }
    glEnd();
}

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if(h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();
    
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // transformações retiradas dos slides.
    float px = r * cos(beta) * sin(alpha);
    float py = r * sin(beta);
    float pz = r * cos(beta) * cos(alpha);
    
    // set the camera
    glLoadIdentity();
    gluLookAt(px,py,pz,
        0.0, 0.0, 0.0,
        0.0f, 1.0f, 0.0f);
    
    draw();
    // End of frame
    glutSwapBuffers();
}

void processKeys(unsigned char c, int xx, int yy) {

}

void processSpecialKeys(int key, int xx, int yy) {

    switch (key) {
        case GLUT_KEY_DOWN:
            if (beta > -M_PI / 2)
                beta -= (float) M_PI / 70;
            break;
        case GLUT_KEY_UP:
            if (beta < M_PI / 2)
                beta += (float) M_PI / 70;
            break;
        case GLUT_KEY_RIGHT:
            alpha += (float) M_PI / 70;
            break;
        case GLUT_KEY_LEFT:
            alpha -= (float) M_PI / 70;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void processMenuEvents(int option) {
    switch (option) {
    case 1:
        glCullFace(GL_BACK);
        break;
    case 2:
        glCullFace(GL_FRONT);
        break;
    case 3:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
    case 4:
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void createGLUTMenus() {

    glutCreateMenu(processMenuEvents);

    glutAddMenuEntry("SEE FRONT", 1);
    glutAddMenuEntry("SEE BACK" , 2);
    glutAddMenuEntry("SEE WIRED", 3);
    glutAddMenuEntry("SEE SOLID", 4);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void readFile (string fich){
    string s;
    ifstream infile;
    string token;
    int pos = 0;
    string delimiter = " ";
    Ponto p;
    float x,y,z;
    
    infile.open(fich);
    while(!infile.eof()){
        getline(infile,s); // Saves the line in STRING.
        if(!s.empty()){
            pos = s.find(delimiter);
            token = s.substr(0,pos);
            x = atof(token.c_str());
            s.erase(0, pos + delimiter.length());
            p.x = x;

            pos = s.find(delimiter);
            token = s.substr(0,pos);
            y = atof(token.c_str());
            s.erase(0, pos + delimiter.length());
            p.y = y;

            pos = s.find(delimiter);
            token = s.substr(0,pos);
            z = atof(token.c_str());
            s.erase(0, pos + delimiter.length());
            p.z = z;
            pontos.push_back(p);
        }
        else {
            break;
        }
    }
    infile.close();
}

void readXML(string fich) {
    
    XMLDocument doc;
    XMLElement *root;
    int i = 0;
    if (!(doc.LoadFile(fich.c_str()))) {
        root = doc.FirstChildElement();
        for (XMLElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
            string ficheiro = elem->Attribute("file");
            cout << "Ficheiro: " << ficheiro << " lido com sucesso" << endl;
            readFile(ficheiro);
            primitivas.insert(pair<int,vector<Ponto>>(i, pontos));
            i++; pontos.clear();
        }
    } else {
        cout << "Ficheiro XML não foi encontrado" << endl;
    }
}

int main(int argc, char **argv){
    
    readXML("/Users/joaonunoabreu/Desktop/2ºSemestre/PROJETOS/CG/Fase1/Engine/config.xml");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Fase 1");
            
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);
    
    createGLUTMenus();
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    glutMainLoop();
    
    return 1;
}
