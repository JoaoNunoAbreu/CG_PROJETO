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

/*void renderScene(void) {

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

static string getElementText(XMLElement *_element) {
    string value;
    if(_element != NULL) {
        value = _element->GetText();
    }
      
    return value;
}*/

void readXML(string fich) {
    
    static const char* xml =
    "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"
    "<entries>"
        "<entry name=\"My First Post\" age=\"52\">I believe every human has a finite number of heartbeats. I don't intend to waste any of mine</entry>"
        "<entry name=\"The Second\" age=\"\">You know, being a test pilot isn't always the healthiest business in the world.</entry>"
        "<entry>Entry</entry>"
        "<entry name=\"The Third\" secretdata=\"9809832\">We have an infinite amount to learn both from nature and from each other</entry>"
        "<entry name=\"Final Post...\" hidden=\"true\" age=\"3\">Across the sea of space, the stars are other suns.</entry>"
    "</entries>";

    XMLDocument doc;
    doc.Parse(xml);
    
    XMLHandle docHandle(&doc);
    
    XMLElement *entry = docHandle.FirstChildElement("entries").ToElement();
    
    if(entry){
        for(XMLNode *node = entry->FirstChildElement(); node; node = node->NextSibling()){
            XMLElement *e = node->ToElement();

            const char *name = e->Attribute("name");
            if(name) cout<<name<<": ";
            
            cout<<e->GetText();
            
            int true_age = e->IntAttribute("age") + 50;
            
            cout<<" "<<true_age <<endl;
            }
        }
}

int main(){
    
    readXML("config.xml");
    
    return 1;
}
