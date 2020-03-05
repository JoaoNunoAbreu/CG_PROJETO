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
float angle3 = 0;

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
    
        glColor3f(1,0.5,1);
    
        glVertex3f(-x/2, 0, -z/2);
        glVertex3f(x/2, 0, z/2);
        glVertex3f(x/2, 0, -z/2);
            
    glEnd();

}

void drawCube(float x, float y, float z, int divisoes) {

    glBegin(GL_TRIANGLES);
    
    float shiftX = x/divisoes;
    float shiftY = y/divisoes;
    float shiftZ = z/divisoes;
    
    for(int i = 0; i < divisoes; i++){
        for(int j = 0; j < divisoes; j++){
            
            // Face frontal
    
            glColor3f((1./divisoes)*i,0,1);
    
            glVertex3f(x/2 , y/2  * shiftY, z/2);
            glVertex3f(-x/2, y/2  * shiftY,z/2);
            glVertex3f(-x/2, -y/2 * shiftY, z/2);
    
            glColor3f((1./divisoes)*j,1,0);
            
            glVertex3f(-x/2, -y/2 * shiftY, z/2);
            glVertex3f(x/2 , -y/2 * shiftY, z/2);
            glVertex3f(x/2 , y/2  * shiftY, z/2);
    
            // Face direita
    
            glColor3f((1./divisoes)*j,0,1);
    
            glVertex3f(x/2 , y/2  * shiftY, -z/2);
            glVertex3f(x/2 , y/2  * shiftY, z/2);
            glVertex3f(x/2 , -y/2 * shiftY, z/2);
    
            glColor3f((1./divisoes)*j,1,0);
            
            glVertex3f(x/2 , -y/2 * shiftY, z/2);
            glVertex3f(x/2 , -y/2 * shiftY, -z/2);
            glVertex3f(x/2 , y/2  * shiftY, -z/2);
    
            // Face de cima
    
            glColor3f((1./divisoes)*j,0,1);
    
            glVertex3f(x/2 , y/2, z/2);
            glVertex3f(x/2 , y/2, -z/2);
            glVertex3f(-x/2, y/2, -z/2);
    
            glColor3f((1./divisoes)*j,1,0);
            
            glVertex3f(-x/2, y/2, -z/2);
            glVertex3f(-x/2, y/2, z/2);
            glVertex3f(x/2 , y/2, z/2);
    
            // Face de trás
    
            glColor3f((1./divisoes)*j,0,1);
    
            glVertex3f(-x/2, y/2 * shiftY, -z/2);
            glVertex3f(x/2 , y/2 * shiftY, -z/2);
            glVertex3f(x/2 , -y/2* shiftY, -z/2);
            
            glColor3f((1./divisoes)*j,1,0);
            
            glVertex3f(x/2 , -y/2* shiftY, -z/2);
            glVertex3f(-x/2, -y/2* shiftY, -z/2);
            glVertex3f(-x/2, y/2 * shiftY, -z/2);
    
            // Face esquerda
    
            glColor3f((1./divisoes)*j,0,1);
    
            glVertex3f(-x/2, y/2 * shiftY, -z/2);
            glVertex3f(-x/2, -y/2* shiftY, -z/2);
            glVertex3f(-x/2, -y/2* shiftY, z/2);
    
            glColor3f((1./divisoes)*j,1,0);
            
            glVertex3f(-x/2, -y/2* shiftY, z/2);
            glVertex3f(-x/2, y/2 * shiftY, z/2);
            glVertex3f(-x/2, y/2 * shiftY, -z/2);
    
            // Face de baixo
    
            glColor3f((1./divisoes)*j,0,1);
    
            glVertex3f(-x/2, -y/2, -z/2);
            glVertex3f(x/2 , -y/2, -z/2);
            glVertex3f(x/2 , -y/2, z/2);
    
            glColor3f((1./divisoes)*j,1,0);
            
            glVertex3f(x/2 , -y/2, z/2);
            glVertex3f(-x/2, -y/2, z/2);
            glVertex3f(-x/2, -y/2, -z/2);
    
        }
    }
    glEnd();

}

void drawSphere(float radius, int slices, int stacks) {
    
    float deslocacao_beta = M_PI / stacks;
    float deslocacao_alpha = 2 * M_PI / slices;
    float beta = -M_PI / 2;
    float alpha = 0;

    float xA, yA, zA;        //Ponto A - canto superior esquerdo
    float xB, yB, zB;        //Ponto B - canto inferior esquerdo
    float xC, yC, zC;        //Ponto C - canto superior direito
    float xD, yD, zD;        //Ponto D - canto inferior direito

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < stacks; i++) {
         for (int j = 0; j < slices; j++) {

            alpha = j * deslocacao_alpha;
            
            xA = radius * cos(beta + deslocacao_beta) * sin(alpha);
            yA = radius * sin(beta + deslocacao_beta);
            zA = radius * cos(beta + deslocacao_beta) * cos(alpha);

            xB = radius * cos(beta) * sin(alpha);
            yB = radius * sin(beta);
            zB = radius * cos(beta) * cos(alpha);

            xC = radius * cos(beta + deslocacao_beta) * sin(alpha + deslocacao_alpha);
            yC = radius * sin(beta + deslocacao_beta);
            zC = radius * cos(beta + deslocacao_beta) * cos(alpha + deslocacao_alpha);

            xD = radius * cos(beta) * sin(alpha + deslocacao_alpha);
            yD = radius * sin(beta);
            zD = radius * cos(beta) * cos(alpha + deslocacao_alpha);

            glColor3f((1. / slices) * i, 0, 1);
            glVertex3f(xC, yC, zC);
            glVertex3f(xA, yA, zA);
            glVertex3f(xB, yB, zB);

            glColor3f((1. / stacks) * i, 0, 1);
            glVertex3f(xB, yB, zB);
            glVertex3f(xD, yD, zD);
            glVertex3f(xC, yC, zC);
   
        }
        beta += deslocacao_beta;
    }
    glEnd();
}

void drawCone(float radius, float height, int slices, int stacks){
    glBegin(GL_TRIANGLES);
    
        float angle = 0; // Ângulo ao centro
        float alfa = (2 * M_PI) / ((float) slices);
        float diffRadius = radius/stacks; // Diferença entre valores de raio de cada stack

        // Coordenadas de referência
        float lowerR = 0;        // Raio do círculo dos 2 pontos inferiores
        float upperR = 0;        // Raio do círculo dos 2 pontos superiores

        // Pontos de referência para aplicar-se a regra da mão direita
        float xA, yA, zA;        //Ponto A - canto inferior esquerdo
        float xB, yB, zB;        //Ponto B - canto inferior direito
        float xC, yC, zC;        //Ponto C - canto superior direito
        float xD, yD, zD;        //Ponto D - canto superior esquerdo
    
        for (int i = 0; i < stacks; i++) {

            lowerR = radius- diffRadius * i;
            upperR = radius- diffRadius * (i+1);
            
            // Percorrem-se as slices e calculam-se as coordenadas
            // dos pontos de referência para a stack e slice atuais
            for (int j = 0; j < slices; j++) {
                angle = alfa * j;

                // Cálculo das novas coordenadas do ponto A
                xA = lowerR * sin(angle);
                yA = i * height/stacks;
                zA = lowerR * cos(angle);

                // Cálculo das novas coordenadas do ponto B
                xB = lowerR * sin(angle + alfa);
                yB = i * height/stacks;
                zB = lowerR * cos(angle + alfa);

                // Cálculo das novas coordenadas do ponto C
                xC = upperR * sin(angle + alfa);
                yC = (i+1) * height/stacks;
                zC = upperR * cos(angle + alfa);

                // Cálculo das novas coordenadas do ponto D
                xD = upperR * sin(angle);
                yD = (i+1) * height/stacks;
                zD = upperR * cos(angle);


                // Inserção dos pontos na estrutura com os resultados
                glColor3f((1./slices)*i,0,1);
                glVertex3f(xA, yA, zA);
                glVertex3f(xB, yB, zB);
                glVertex3f(xC, yC, zC);

                glColor3f((1./stacks)*j,0,1);
                glVertex3f(xA, yA, zA);
                glVertex3f(xC, yC, zC);
                glVertex3f(xD, yD, zD);
            }
        }
    
        alfa = -alfa; // Para vermos a base do cone, usando a regra da mão direita
    
        for(int i = 0; i < slices; i++){
            glColor3f(1,0,1);
            glVertex3f(0,0,0);
            glVertex3f(radius*sin(alfa*i),0,radius*cos(alfa*i));
            glVertex3f(radius*sin(alfa*(i+1)),0,radius*cos(alfa*(i+1)));
        }
    
    glEnd();
}

void drawCube2(float x, float y, float z, int d) {
    glBegin(GL_TRIANGLES);

    float xShift = x / d;
    float yShift = y / d;
    float zShift = z / d;

    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d; j++) {
            for (int k = 0; k <= d; k++) {

                glColor3f((1. / d) * i, 0, 1);

                glVertex3f(xShift * i, yShift * j, zShift * k);
            }
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
    glRotatef(angle1,0,1,0);
    glRotatef(angle2,0,0,1);
    glRotatef(angle3,1,0,0);
    //drawPlane(2, 2);
    drawCube2(2,2,2,3);
    //drawSphere(2, 100, 100);
    //drawCone(2,2,8,100);
    //glutWireCone(6, 6, 4, 4);
    //glColor3f(1,1,1);
    //glutWireCone(4, 6, 4, 4);
    
    
    
    
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
        case GLUT_KEY_F1:
            angle3-=5;
            break;
        case GLUT_KEY_F2:
            angle3+=5;
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
