#include <stdio.h>

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


#define ARVORES 400
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct Ponto {
    float x;
    float y;
    float z;
};

vector<Ponto> pontos;

float alfa = 0.0f, beta = 0.5f, radius = 100.0f;
float camX, camY, camZ;
float r = 50;
float ri = 35;
float rc = 15;
float deslocacao = 0;


void drawHollowCircle(GLfloat radius, int lineAmount){
    int i;
    
    GLfloat twicePi = 2.0f * M_PI;

    glBegin(GL_LINE_LOOP);
        for(i = 0; i <= lineAmount;i++) {
            glVertex3f(radius * sin(i *  twicePi / lineAmount),0,radius* cos(i * twicePi / lineAmount));
        }
    glEnd();
}

void drawCircles(){
    
    glColor3f(1, 0, 0);
    drawHollowCircle(35,100);
    drawHollowCircle(50,100);
}

void drawDonut() {

    glPushMatrix();
    glTranslatef(0.0,0.6,0.0);
    glColor3f(1.0f,0.0f,1.0f);
    glutSolidTorus(0.5,1.25,8,16);
    glPopMatrix();
}


void drawTrees(){
    for(int i = 0; i < pontos.size(); i++){
        
        // Tronco
        glPushMatrix();
        glTranslatef(pontos[i].x, 0, pontos[i].z);
        glRotatef(90, -1, 0, 0);
        glColor3f(1, 0.5, 0);
        glutSolidCone(1,10,6,2);
        glPopMatrix();
        
        // Folhas
        glPushMatrix();
        glTranslatef(pontos[i].x, 5, pontos[i].z);
        glRotatef(90, -1, 0, 0);
        glColor3f(0.02, 0.41, 0.01);
        glutSolidCone(3,10,6,2);
        glPopMatrix();
    }
}

void drawTeaPotBigCircle(int tPots){
    float angle = 0;
    float z ;
    float x;
    for(int i = 0;i < tPots; i++) {
        angle = i*((2*M_PI)/tPots) + deslocacao * 0.5f;
        x = ri * sin(angle);
        z = ri * cos(angle);
        glPushMatrix();
        glTranslatef(x, 2, z);
        glRotatef(angle*(180/M_PI),0,1,0);
        glColor3f(1, 0, 0);
        glutSolidTeapot(2);
        glPopMatrix();

    }
}

void drawTeaPotSmallCircle(int tPots){
    float angle = 0;
    float z ;
    float x;
    for(int i = 0; i < tPots; i++) {
        angle = i*((2*M_PI)/tPots) - deslocacao;
        x = rc * sin(angle);
        z = rc * cos(angle);
        glPushMatrix();
        glTranslatef(x, 2, z);
        glRotatef((angle-M_PI/2)*(180/M_PI),0,1,0);
        glColor3f(0, 0, 1);
        glutSolidTeapot(2);
        glPopMatrix();

    }
}

void calculaPontos(){
    
    float alpha;
    float rr;
    float x,z;
    int i = 0;
    Ponto p;
    while(i < ARVORES){
        
        rr = rand() * (sqrt(2*pow(100,2)))/ RAND_MAX;
        alpha = rand() * 2*M_PI / RAND_MAX;

        x = sin(alpha) * (rr + r);
        z = cos(alpha) * (rr + r);
        
        if(fabs(x) < 100 && fabs(z) < 100){
            p.x = x;
            p.y = 0;
            p.z = z;
            
            pontos.push_back(p);
            i++;
        }
    }
}

void spherical2Cartesian() {

    camX = radius * cos(beta) * sin(alfa);
    camY = radius * sin(beta);
    camZ = radius * cos(beta) * cos(alfa);
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

    // set the camera
    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
        0.0, 0.0, 0.0,
        0.0f, 1.0f, 0.0f);
    
    glColor3f(0.2f, 0.8f, 0.2f);
    glBegin(GL_TRIANGLES);
        glVertex3f(100.0f, 0, -100.0f);
        glVertex3f(-100.0f, 0, -100.0f);
        glVertex3f(-100.0f, 0, 100.0f);

        glVertex3f(100.0f, 0, -100.0f);
        glVertex3f(-100.0f, 0, 100.0f);
        glVertex3f(100.0f, 0, 100.0f);
    glEnd();
    
    drawCircles();
    drawTrees();
    drawDonut();
    drawTeaPotBigCircle(16);
    drawTeaPotSmallCircle(8);
    
    deslocacao += 0.03;
    
    // End of frame
    glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

// put code to process regular keys in here

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


void printInfo() {

    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));

    printf("\nUse Arrows to move the camera up/down and left/right\n");
    printf("Home and End control the distance from the camera to the origin");
}


int main(int argc, char **argv) {

    calculaPontos();
    
// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI-UM");
        
// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    
// Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    spherical2Cartesian();
    printInfo();
    
// enter GLUT's main cycle
    glutMainLoop();
    
    return 1;
}
