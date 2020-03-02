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

float angle1 = 0;
float angle2 = 0;

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

void drawAxis(){
    
    glBegin(GL_LINES);
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
    glEnd();
}

void drawPlane(float x, float z) {

    glBegin(GL_TRIANGLES);
        
        glColor3f(1,0.5,0);
    
        glVertex3f(-x/2, 0, -z/2);
        glVertex3f(-x/2, 0, z/2);
        glVertex3f(x/2, 0, z/2);
    
        glVertex3f(-x/2, 0, -z/2);
        glVertex3f(x/2, 0, z/2);
        glVertex3f(x/2, 0, -z/2);
            
    glEnd();

}

void drawCube(float x, float y, float z) {

    glBegin(GL_TRIANGLES);
    
        // Face frontal
    
        glColor3f(1,0.5,0);
    
        glVertex3f(x/2, y/2, z/2);
        glVertex3f(-x/2, y/2,z/2);
        glVertex3f(-x/2, -y/2, z/2);
    
        glVertex3f(-x/2, -y/2, z/2);
        glVertex3f(x/2, -y/2, z/2);
        glVertex3f(x/2, y/2, z/2);
    
        // Face direita
    
        glColor3f(1, 0, 0);
    
        glVertex3f(x/2, y/2, -z/2);
        glVertex3f(x/2, y/2, z/2);
        glVertex3f(x/2, -y/2, z/2);
    
        glVertex3f(x/2, -y/2, z/2);
        glVertex3f(x/2, -y/2, -z/2);
        glVertex3f(x/2, y/2, -z/2);
    
        // Face de cima
    
        glColor3f(0, 0, 1);
    
        glVertex3f(x/2, y/2, z/2);
        glVertex3f(x/2, y/2, -z/2);
        glVertex3f(-x/2, y/2, -z/2);
    
        glVertex3f(-x/2, y/2, -z/2);
        glVertex3f(-x/2, y/2, z/2);
        glVertex3f(x/2, y/2, z/2);
    
        // Face de trás
    
        glColor3f(0, 1, 0);
    
        glVertex3f(-x/2, y/2, -z/2);
        glVertex3f(x/2, y/2, -z/2);
        glVertex3f(x/2, -y/2, -z/2);
    
        glVertex3f(x/2, -y/2, -z/2);
        glVertex3f(-x/2, -y/2, -z/2);
        glVertex3f(-x/2, y/2, -z/2);
    
        // Face esquerda
    
        glColor3f(0,0.5,1);
    
        glVertex3f(-x/2, y/2, -z/2);
        glVertex3f(-x/2, -y/2, -z/2);
        glVertex3f(-x/2, -y/2, z/2);
    
        glVertex3f(-x/2, -y/2, z/2);
        glVertex3f(-x/2, y/2, z/2);
        glVertex3f(-x/2, y/2, -z/2);
    
        // Face de baixo
    
        glColor3f(0.5,0,1);
    
        glVertex3f(-x/2, -y/2, -z/2);
        glVertex3f(x/2, -y/2, -z/2);
        glVertex3f(x/2, -y/2, z/2);
    
        glVertex3f(x/2, -y/2, z/2);
        glVertex3f(-x/2, -y/2, z/2);
        glVertex3f(-x/2, -y/2, -z/2);
    
            
    glEnd();

}

void drawSphere(float r, int slices, int stacks){
    
    float alpha = 0;
    float beta = 0;
    glBegin(GL_LINE_LOOP);
    
    for(int i = 0; i < slices; i++){
        alpha = 2 * M_PI * i/slices;
        for(int j = 0; j < stacks; j++){
            
            beta = 2 * M_PI * j/stacks;
            float x = r * cos(beta) * sin(alpha);
            float y = r * sin(beta);
            float z = r * cos(beta) * cos(alpha);
            
            glVertex3f(x,y,z);
        }
    }
    glEnd();
}

void drawCone(float r, float height, int slices, int stacks){
    
    float alpha = 0;
    float beta = 0;
    glBegin(GL_LINE_LOOP);
    
    for(int i = 0; i < slices; i++){
        alpha = 2 * M_PI * i/slices;
        for(int j = 0; j < stacks; j++){
            
            beta = 2 * M_PI * j/stacks;
            r = r - r/stacks;
            float x = r * cos(beta) * sin(alpha);
            float y = r * sin(beta);
            float z = r * cos(beta) * cos(alpha);
            
            glVertex3f(x,y,z);
        }
    }
    glEnd();
    
}

void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(5,5,5,
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);
    
    drawAxis();
    // drawPlane(4,4);
    glRotatef(angle1,0,1,0);
    glRotatef(angle2,0,0,1);
    //drawCube(2,2,2);
    //drawSphere(2, 50, 50);
    drawCone(2,3,50,50);
    
    // End of frame
    glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

// put code to process regular keys in here

}


void processSpecialKeys(int key, int xx, int yy) {
    switch (key){
        case GLUT_KEY_LEFT:
            angle1-=5;
            break;
        case GLUT_KEY_RIGHT:
            angle1+=5;
            break;
        case GLUT_KEY_UP:
            angle2+=5;
            break;
        case GLUT_KEY_DOWN:
            angle2-=5;
        break;
    }
    glutPostRedisplay();

}


int main(int argc, char **argv) {

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("CG@DI-UM");
        
// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    
// Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
// enter GLUT's main cycle
    glutMainLoop();
    
    return 1;
}
