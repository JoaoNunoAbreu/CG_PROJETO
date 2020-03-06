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
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

// para o lookAt (??????)
float radius = 5;
float alpha = 0;
float beta = 0;

struct Ponto {
    float x;
    float y;
    float z;
};

vector<Ponto> vertexes; //vertices lidos do ficheiro

void draw(){
    
    glBegin(GL_TRIANGLES);
    
        // X axis in red
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(100.0f, 0.0f, 0.0f);
        // Y Axis in Green
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 100.0f, 0.0f);
        // Z Axis in Blue
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 100.0f);
    
    
        for(int i = 0; i < vertexes.size(); i++) {
            glVertex3f(vertexes[i].x, vertexes[i].y, vertexes[i].z);
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

    float px = radius * cos(beta) * sin(alpha);
    float py = radius * sin(beta);
    float pz = radius * cos(beta) * cos(alpha);
    
    // set the camera
    glLoadIdentity();
    gluLookAt(px, py, pz,
        0.0, 0.0, 0.0,
        0.0f, 1.0f, 0.0f);
    
    draw();
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

void readFile (string fich){
    string s;
    ifstream infile;
    infile.open (fich);
    string token;
    int pos = 0;
    string delimiter = " ";
    Ponto p;
    float x,y,z;
        while(!infile.eof()){
           
            getline(infile,s); // Saves the line in STRING.
            cout << s; // Prints our STRING.
        
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

            vertexes.push_back(p);
        }
    infile.close();
}

void readXML(string fich) {
    
    XMLDocument doc;
    XMLElement *root;

    if (!(doc.LoadFile(fich.c_str()))) {
        root = doc.FirstChildElement();
        for (XMLElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
            string ficheiro = elem->Attribute("file");
            cout << "Ficheiro:" << ficheiro << " lido com sucesso" << endl;
            readFile(ficheiro);
        }
    } else {
        cout << "Ficheiro XML não foi encontrado" << endl;
    }
}

int main(int argc, char **argv){
    //readXML("config.xml");
    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Fase 1");
            
    // Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
    // Callback registration for keyboard processing
    glutSpecialFunc(processSpecialKeys);
    
    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
        
    // enter GLUT's main cycle
    glutMainLoop();
    
    return 1;
}
