#include <stdlib.h>
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <direct.h>
#include <GL/glew.h>
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
#include "headers/Rotacao.h"
#include "headers/Transformacao.h"
#include "headers/Translacao.h"
#include "headers/Cor.h"
#include "headers/Escala.h"
#include "headers/tinyxml2.h"
#include "headers/Grupo.h"
#include "../include/Ponto.h"
#include "headers/CatmullRomCurve.h"

using namespace tinyxml2;
using namespace std;

float alfa = 0.7f, beta = 0.5f, radius = 200.0f;
float camX, camY, camZ;

int timebase = 0, frame = 0;

Grupo g;

void drawAxis(){
    
    glPushMatrix();
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
    glPopMatrix();
    
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
    float fps;
    int time;
    char s[64];
    time = glutGet(GLUT_ELAPSED_TIME);
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // transformações retiradas dos slides.
    
    // set the camera
    glLoadIdentity();
    gluLookAt(camX,camY,camZ,
        0.0, 0.0, 0.0,
        0.0f, 1.0f, 0.0f);
    
    //drawAxis();
    g.drawGroup(time);
    
    frame++;
   
    if (time - timebase > 1000) {
        fps = frame * 1000.0 / (time - timebase);
        timebase = time;
        frame = 0;
        sprintf(s, "FPS: %f6.2", fps);
        glutSetWindowTitle(s);
    }
    
    // End of frame
    glutSwapBuffers();
}

void spherical2Cartesian() {

    camX = radius * cos(beta) * sin(alfa);
    camY = radius * sin(beta);
    camZ = radius * cos(beta) * cos(alfa);
}


void processKeys(unsigned char c, int xx, int yy) {

}

void processSpecialKeys(int key, int xx, int yy) {

    switch (key) {

    case GLUT_KEY_RIGHT:
        alfa -= 0.1; break;

    case GLUT_KEY_LEFT:
        alfa += 0.1; break;

    case GLUT_KEY_UP:
        beta += 0.1f;
        if (beta > 1.5f)
            beta = 1.5f;
        break;

    case GLUT_KEY_DOWN:
        beta -= 0.1f;
        if (beta < -1.5f)
            beta = -1.5f;
        break;

    case GLUT_KEY_PAGE_DOWN: radius -= 5.0f;
        if (radius < 1.0f)
            radius = 1.0f;
        break;

    case GLUT_KEY_PAGE_UP: radius += 5.0f; break;
    
    
    }
    spherical2Cartesian();
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

void readFile (Grupo &grupo, string filename){
    
    ifstream infile;
   
        infile.open(filename);
        if (infile.is_open()) {

            cout << "Ficheiro = " << filename << endl;

            string s;
            string token;

            size_t pos = 0;

            string delimiter = " ";
           
            glEnableClientState(GL_VERTEX_ARRAY);

            vector<float> model;
       
            float x, y, z;

            while (!infile.eof()) {

                int i = 0;
                getline(infile, s); // Saves the line in STRING.
                // cout << "s = " << s << endl;
                while ((pos = s.find(delimiter)) != std::string::npos) {

                    token = s.substr(0, pos);

                    if (i == 0) {
                        x = atof(token.c_str());
                        model.push_back(x);
                    }

                    else if (i == 1) {
                        y = atof(token.c_str());
                        model.push_back(y);
                    }
                    s.erase(0, pos + delimiter.length());
                    i++;
                }
                z = atof(s.c_str());
             
                model.push_back(z);
            }

            // gera VBO
            int size = model.size();
            GLuint buffer;
            VBO v;

            glGenBuffers(1, &buffer);
            glBindBuffer(GL_ARRAY_BUFFER, buffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float) * model.size(), model.data(), GL_STATIC_DRAW);

            v.size = model.size()/3 ;
            v.vertices = buffer;

            grupo.addModel(v);

            infile.close();
        }
}


void loadControlPoints(vector<Ponto>& controlpoints, XMLElement* elem) {
    
    XMLElement* elem2;

    for (elem2 = elem->FirstChildElement(); elem2 != NULL; elem2 = elem2->NextSiblingElement()) {
        string tag = elem2->Value();
        Ponto p;

        p.x = stof(elem2->Attribute("X")); //Retira X
        p.y = stof(elem2->Attribute("Y")); //Retira Y
        p.z = stof(elem2->Attribute("Z")); //Retira Z
       
        controlpoints.push_back(p);
    }
    
    if (controlpoints.size() < 4) { //garante que a catmull tem no minimo quatro pontos de controlo.
        cout << "Pontos insuficientes" << endl;
        return;
    }
}


void parseGroup(Grupo &grupo, XMLElement *group){

    XMLElement * elem;
    float x=0,y=0.0f,z=0.0f,angle=0.0f;

 
    // vai iterar o grupo
    for(elem = group->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {

        string tag = elem->Value();
        
        if(tag == "group"){
       
            Grupo childGroup;
            parseGroup(childGroup, elem);
            grupo.addChilds(childGroup);
        }
        else if(tag=="translate"){
            vector<Ponto> controlPoints;
            float tempo = 0.0f;
            int flag = 0;
         
            
            if ((elem->Attribute("time"))) {
                tempo = stof(elem->Attribute("time"));
                loadControlPoints(controlPoints, elem);
                flag = 1;
            }
            
            if (!flag) {
                x = stof(elem->Attribute("X")); //Retira X
                y = stof(elem->Attribute("Y")); //Retira Y
                z = stof(elem->Attribute("Z")); //Retira Z
            }

            Translacao *t = new Translacao(x,y,z,tempo,controlPoints);
     
            grupo.addTransformation(t);
        }
        else if(tag=="rotate"){
          
            float tempo = 0.0f;
            int flag = 0;

            if ((elem->Attribute("time"))) {
                tempo = stof(elem->Attribute("time"));
                flag = 1;
            }

            if(!flag)
            angle = stof(elem->Attribute("angle")); //Retira angulo

            x = stof(elem->Attribute("X"));  //Retira X
            y = stof(elem->Attribute("Y")); //Retira Y
            z = stof(elem->Attribute("Z")); //Retira Z

            Rotacao *r = new Rotacao(angle,tempo,x,y,z);
            grupo.addTransformation(r);
        }
        else if(tag=="scale"){
        
            x = stof(elem->Attribute("X")); //Retira X
            y = stof(elem->Attribute("Y")); //Retira Y
            z = stof(elem->Attribute("Z")); //Retira Z
            Escala *e = new Escala(x,y,z);
            grupo.addTransformation(e);
        }
        else if(tag =="colour"){
        
            x = stof(elem->Attribute("R")); //Retira R
            y = stof(elem->Attribute("G")); //Retira G
            z = stof(elem->Attribute("B")); //Retira B
            Cor *c = new Cor(x,y,z);
            grupo.addTransformation(c);
        }
        else if(tag=="models"){
            //PERCORRE MODELS
            for(XMLElement* models = group->FirstChildElement("models")->FirstChildElement("model"); models; models = models -> NextSiblingElement("model")){
                string ficheiro = models->Attribute("file");
                readFile(grupo,ficheiro);
            }
        }
    }
}


void readXML(string file){

    tinyxml2 :: XMLDocument doc;
    if(!doc.LoadFile(file.c_str())){
        cout << "Ficheiro XML lido" << endl;
        XMLElement * root = doc.RootElement();  //obtem a tag scene
        XMLElement * group = root->FirstChildElement(); //obtem o primeiro grupo
        parseGroup(g,group);
    } else {
        cout << "Ficheiro XML não lido" << endl;
    }
}


int main(int argc, char **argv){
   
    glutInit(&argc, argv);
  
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Fase 3");
    
    #ifndef __APPLE__
    // init GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        cout << "Glew está com problemas" << endl;
        cout << glewGetErrorString(err) << endl;
        return 0;
    }
    #endif

    readXML("config.xml");


    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);
    
    createGLUTMenus();

   

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    spherical2Cartesian();

  

    glutMainLoop();
    
    return 1;
}
