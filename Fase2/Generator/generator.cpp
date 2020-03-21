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
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void drawPlane(float x, float z, string filename) {

    ofstream file(filename);
    if(file.is_open()){
    
        file << "" << (-x/2) << " 0 " << (-z/2) << "\n";
        file << "" << (-x/2) << " 0 " << (z/2) << "\n";
        file << "" << (x/2)  << " 0 " << (z/2) << "\n";
        
        file << "" << (-x/2) << " 0 " << (-z/2) << "\n";
        file << "" << (x/2)  << " 0 " << (z/2) << "\n";
        file << "" << (x/2)  << " 0 " << (-z/2) << "\n";
        
        file << "" << (-x/2) << " 0 " << (-z/2) << "\n";
        file << "" << (x/2)  << " 0 " << (z/2) << "\n";
        file << "" << (-x/2) << " 0 " << (z/2) << "\n";
        
        file << "" << (-x/2) << " 0 " << (-z/2) << "\n";
        file << "" << (x/2)  << " 0 " << (-z/2) << "\n";
        file << "" << (x/2)  << " 0 " << (z/2) << "\n";

    }
    file.close();
}

void drawCube(float x, float y, float z, int d, string filename) {
    
    ofstream file(filename);
    if(file.is_open()){
        float xShift = x / d;
        float yShift = y / d;
        float zShift = z / d;

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                for (int k = 0; k < d; k++) {

                    // face tras
                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * k            << "\n";
                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * j        << " " << zShift * k            << "\n";

                    file << "" << xShift * (i + 1)  << " " << yShift * j        << " " << zShift * k            << "\n";
                    file << "" << xShift * i        << " " << yShift * (j+1)    << " " << zShift * k            << "\n";
                    file << "" << xShift * (i+1)    << " " << yShift * (j+1)    << " " << zShift * k            << "\n";
                    
                    // face esquerda
                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * k            << "\n";
                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";

                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";
                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * i        << " " << yShift * (j+1)    << " " << zShift * (k+1)        << "\n";
                    
                    // face baixo
                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * k            << "\n";
                    file << "" << xShift * (i+1)    << " " << yShift * j        << " " << zShift * k            << "\n";
                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";

                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * j        << " " << zShift * k            << "\n";
                    file << "" << xShift * (i+1)    << " " << yShift * j        << " " << zShift * (k+1)        << "\n";
                    
                    // face direita
                    file << "" << xShift * (i+1)    << " " << yShift * j        << " " << zShift * k            << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";
                    file << "" << xShift * (i+1)    << " " << yShift * j        << " " << zShift * (k+1)        << "\n";

                    file << "" << xShift * (i + 1)  << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * (j + 1)  << " " << zShift * (k + 1)      << "\n";

                    // face frente
                    file << "" << xShift * i        << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * (k + 1)      << "\n";

                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * j        << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * (j + 1)  << " " << zShift * (k + 1)      << "\n";

                    // face cima
                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";
                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";

                    file << "" << xShift * (i + 1)  << " " << yShift * (j + 1)  << " " << zShift * k            << "\n";
                    file << "" << xShift * i        << " " << yShift * (j + 1)  << " " << zShift * (k + 1)      << "\n";
                    file << "" << xShift * (i + 1)  << " " << yShift * (j + 1)  << " " << zShift * (k + 1)      << "\n";
                }
            }
        }
    }
    file.close();
}

void drawSphere(float radius, int slices, int stacks, string filename) {
    
    float deslocacao_beta = M_PI / stacks;
    float deslocacao_alpha = 2 * M_PI / slices;
    float beta = -M_PI / 2;
    float alpha = 0;

    float xA, yA, zA;        //Ponto A - canto superior esquerdo
    float xB, yB, zB;        //Ponto B - canto inferior esquerdo
    float xC, yC, zC;        //Ponto C - canto superior direito
    float xD, yD, zD;        //Ponto D - canto inferior direito
    
    ofstream file(filename);
    if(file.is_open()){
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

                file << "" << xC << " " << yC << " " << zC << "\n";
                file << "" << xA << " " << yA << " " << zA << "\n";
                file << "" << xB << " " << yB << " " << zB << "\n";

                file << "" << xB << " " << yB << " " << zB << "\n";
                file << "" << xD << " " << yD << " " << zD << "\n";
                file << "" << xC << " " << yC << " " << zC << "\n";
   
            }
            beta += deslocacao_beta;
        }
    }
    file.close();
}
void drawCone(float radius, float height, int slices, int stacks, string filename){
    
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

    ofstream file(filename);
    if(file.is_open()){
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
                file << "" << xA << " " << yA << " " << zA << "\n";
                file << "" << xB << " " << yB << " " << zB << "\n";
                file << "" << xC << " " << yC << " " << zC << "\n";

                file << "" << xA << " " << yA << " " << zA << "\n";
                file << "" << xC << " " << yC << " " << zC << "\n";
                file << "" << xD << " " << yD << " " << zD << "\n";
            }
        }
    
        alfa = -alfa; // Para vermos a base do cone, usando a regra da mão direita
    
        for(int i = 0; i < slices; i++){
            file << "" << "0" << " " << "0" << " " << "0" << "\n";
            file << "" << radius*sin(alfa*i) << " " << "0" << " " << radius*cos(alfa*i) << "\n";
            file << "" << radius*sin(alfa*(i+1)) << " " << "0" << " " << radius*cos(alfa*(i+1)) << "\n";
        }
    }
    file.close();
}

int main(int argc, char **argv) {

    
    /* EXEMPLO:
        generator plane x z plane.3d
        generator cube x y z divisoes cube.3d
        generator sphere r slices stacks sphere.3d
        generator cone r h slices stacks cone.3d
     */
    
    if(argc == 5 && !strcmp(argv[1],"plane")){
        drawPlane(atof(argv[2]),atof(argv[3]),argv[4]);
    }
    else if(argc == 7 && !strcmp(argv[1],"cube")){
        drawCube(atof(argv[2]),atof(argv[3]),atof(argv[4]),atoi(argv[5]),argv[6]);
    }
    else if(argc == 6 && !strcmp(argv[1],"sphere")){
        drawSphere(atof(argv[2]),atoi(argv[3]),atoi(argv[4]),argv[5]);
    }
    else if (argc == 7 && !strcmp(argv[1],"cone")){
        drawCone(atof(argv[2]),atof(argv[3]),atoi(argv[4]),atoi(argv[5]),argv[6]);
    }
    
    return 1;
}
