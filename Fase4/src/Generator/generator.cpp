#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "../Common/Textura.h"
#include "headers/BezierPatch.h"

constexpr auto INDEX_PER_PATCH = 16;

using namespace std;

void drawPlane(float ladox, float ladoz, string f){
    float x, y = 0, z;
    ofstream file(f);


    x = ladox/2;
    z = ladoz/2;

    // Triangulo 1
    file << x << " "    << y << " " << z    << endl;
    file << 0 << " "    << 1 << " " << 0    << endl;
    file << 1 << " "    << 1                << endl;


    file << x << " "    << y << " " << -z   << endl;
    file << 0 << " "    << 1 << " " << 0    << endl;
    file << 1 << " "    << 0                << endl;

    file << -x << " "   << y << " " << -z   << endl;
    file << 0 << " "    << 1 << " " << 0    << endl;
    file << 0 << " "    << 0                << endl;


    // Triangulo 2
    file << -x << " "   << y << " " << z    << endl;
    file << 0 << " "    << 1 << " " << 0    << endl;
    file << 0 << " "    << 1                << endl;


    file << x << " "    << y << " " << z    << endl;
    file << 0 << " "    << 1 << " " << 0    << endl;
    file << 1 << " "    << 1                << endl;   


    file << -x << " "   << y << " " << -z   << endl;
    file << 0 << " "    << 1 << " " << 0    << endl;
    file << 0 << " "    << 0                << endl;

    file.close();
}

void drawCube(float x,float y,float z,int d,string filename) {

    float xShift = x / d;
    float yShift = y / d;
    float zShift = z / d;

    ofstream file(filename);
    if (file.is_open()) {

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {

                // face tras itera para a direita
                file << "" << xShift * j     << " " << yShift * i           << " " << 0                   << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << -1.0f               << endl;
                file << "" << (float)j / d   << " " << (float)i / d                                       << endl;

                file << "" << xShift * j     << " " << yShift *(i+1)        << " " <<  0                  << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << -1.0f               << endl;
                file << "" << (float)j / d   << " " << (float)(i+1)/d                                     << endl;

                file << "" << xShift *(j+1)  << " " << yShift * i           << " " << 0                   << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << -1.0f               << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                // -------------------

                file << "" << xShift *(j+1)  << " " << yShift * i           << " " << 0                   << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << -1.0f               << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                file << "" << xShift * j     << " " << yShift * (i + 1)     << " " << 0                   << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << -1.0f               << endl;
                file << "" << (float)j / d   << " " << (float)(i + 1) / d                                 << endl;

                file << "" << xShift *(j+1)  << " " << yShift * (i + 1)     << " " << 0                   << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << -1.0f               << endl;
                file << "" << (float)(j+1)/d << " " << (float)(i + 1) / d                                 << endl;

                // face esquerda itera verticalmente
                file << "" << 0              << " " << yShift * i           << " " << zShift*j            << endl;
                file << "" << -1.0f          << " " << 0.0f                 << " " << 0.0f                << endl;
                file << ""                   << (float)i / d                << " " << (float)j/d          << endl;

                file << "" << 0              << " " << yShift * i           << " " << zShift*(j+1)        << endl;
                file << "" << -1.0f          << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)i / d   << " " << (float)(j + 1) / d                                 << endl;

                file << "" << 0              << " " << yShift * (i + 1)     << " " << zShift * j          << endl;
                file << "" << -1.0f          << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(i+1)/d << " " << (float)j / d                                       << endl;

                // -------------------

                file << "" << 0              << " " << yShift * (i + 1)     << " " << zShift * j          << endl;
                file << "" << -1.0f          << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(i+1)/d << " " << (float)j / d                                       << endl;

                file << "" << 0              << " " << yShift * i           << " " << zShift * (j + 1)    << endl;
                file << "" << -1.0f          << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)i / d   << " " << (float)(j + 1) / d                                 << endl;

                file << "" << 0              << " " << yShift * (i + 1)     << " " << zShift * (j + 1)    << endl;
                file << "" << -1.0f          << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(i+1)/d << " " << (float)(j + 1) / d                                 << endl;


                // face baixo itera para  a direita
                file << "" << xShift * j     << " " << 0                    << " " << zShift * i          << endl;
                file << "" << 0.0f           << " " << -1.0f                << " " << 0.0f                << endl;
                file << "" << (float)j / d   << " " << (float)i / d                                       << endl;

                file << "" << xShift *(j+1)  << " " << 0                    << " " << zShift * i          << endl;
                file << "" << 0.0f           << " " << -1.0f                << " " << 0.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                file << "" << xShift * j     << " " << 0                    << " " << zShift * (i + 1)    << endl;
                file << "" << 0.0f           << " " << -1.0f                << " " << 0.0f                << endl;
                file << "" << (float)j / d   << " " << (float)(i + 1) / d                                 << endl;

                // -------------------

                file << "" << xShift * j     << " " << 0.0f                 << " " << zShift * (i + 1)    << endl;
                file << "" << 0.0f           << " " << -1.0f                << " " << 0.0f                << endl;
                file << "" << (float)j / d   << " " << (float)(i + 1) / d                                 << endl;

                file << "" << xShift *(j+1)  << " " << 0.0f                 << " " << zShift * i          << endl;
                file << "" << 0.0f           << " " << -1.0f                << " " << 0.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                file << "" << xShift *(j+1)  << " " << 0.0f                 << " " << zShift * (i + 1)    << endl;
                file << "" << 0.0f           << " " << -1.0f                << " " << 0.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)(i + 1) / d                                 << endl;

                // face direita itera para  a frente
                file << "" << xShift * d     << " " << yShift * i           << " " << zShift * j          << endl;
                file << "" << 1.0f           << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)i / d   << " " << (float)j / d                                       << endl;

                file << "" << xShift * d     << " " << yShift * (i + 1)     << " " << zShift * j          << endl;
                file << "" << 1.0f           << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(i+1)/d << " " << (float)j / d                                       << endl;

                file << "" << xShift* d      << " " << yShift* i            << " " << zShift* (j + 1)     << endl;
                file << "" << 1.0f           << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)i / d   << " " << (float)(j + 1) / d                                 << endl;

                // -------------------

                file << "" << xShift* d      << " " << yShift* i            << " " << zShift* (j + 1)     << endl;
                file << "" << 1.0f           << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)i / d   << " " << (float)(j + 1) / d                                 << endl;

                file << "" << xShift* d      << " " << yShift* (i + 1)      << " " << zShift* j           << endl;
                file << "" << 1.0f           << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(i+1)/d << " " << (float)j / d                                       << endl;

                file << "" << xShift * d     << " " << yShift * (i + 1)     << " " << zShift * (j + 1)    << endl;
                file << "" << 1.0f           << " " << 0.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(i+1)/d << " " << (float)(j + 1) / d                                 << endl;

                // face frente itera pra a direita
                file << "" << xShift * j     << " " << yShift * i           << " " << zShift * d          << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << 1.0f                << endl;
                file << "" << (float)j / d   << " " << (float)i / d                                       << endl;

                file << "" << xShift * (j+1) << " " << yShift * i           << " " << zShift * d          << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << 1.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                file << "" << xShift * j     << " " << yShift * (i + 1)     << " " << zShift * d          << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << 1.0f                << endl;
                file << "" << (float)j / d   << " " << (float)(i + 1) / d                                 << endl;

                // -------------------

                file << "" << xShift * j     << " " << yShift * (i + 1)     << " " << zShift * d          << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << 1.0f                << endl;
                file << "" << (float)j / d   << " " << (float)(i + 1) / d                                 << endl;

                file << "" << xShift *(j+1)  << " " << yShift * i           << " " << zShift * d          << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << 1.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                file << "" << xShift *(j+1)  << " " << yShift * (i + 1)     << " " << zShift * d          << endl;
                file << "" << 0.0f           << " " << 0.0f                 << " " << 1.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)(i + 1) / d                                 << endl;

                // face cima itera para a diretita
                file << "" << xShift * j     << " " << yShift * d           << " " << zShift * i          << endl;
                file << "" << 0.0f           << " " << 1.0f                 << " " << 0.0f                << endl;
                file << "" << (float)j / d   << " " << (float)i / d                                       << endl;

                file << "" << xShift * j     << " " << yShift * d           << " " << zShift * (i + 1)    << endl;
                file << "" << 0.0f           << " " << 1.0f                 << " " << 0.0f                << endl;
                file << "" << (float)j / d   << " " << (float)(i + 1) / d                                 << endl;

                file << "" << xShift *(j+1)  << " " << yShift * d           << " " << zShift * i          << endl;
                file << "" << 0.0f           << " " << 1.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                // -------------------

                file << "" << xShift *(j+1)  << " " << yShift * d           << " " << zShift * i          << endl;
                file << "" << 0.0f           << " " << 1.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)i / d                                       << endl;

                file << "" << xShift * j     << " " << yShift * d           << " " << zShift * (i + 1)    << endl;
                file << "" << 0.0f           << " " << 1.0f                 << " " << 0.0f                << endl;
                file << "" << (float)j / d   << " " << (float)(i + 1) / d                                 << endl;

                file << "" << xShift * (j+1) << " " << yShift * d           << " " << zShift * (i + 1)    << endl;
                file << "" << 0.0f           << " " << 1.0f                 << " " << 0.0f                << endl;
                file << "" << (float)(j+1)/d << " " << (float)(i + 1) / d                                 << endl;
            }
        }
    }
    file.close();
}

void drawSphere(float radius, int slices, int stacks, string filename)
{

    float deslocacao_beta = M_PI / stacks;
    float deslocacao_alpha = 2 * M_PI / slices;
    float beta = -M_PI / 2;
    float alpha = 0;

    float texture_stacks_step = 1.0 / (float)stacks;
    float texture_slices_step = 1.0 / (float)slices;

    float xA = 0, yA = 0, zA = 0; // Ponto A - canto superior esquerdo
    float xB = 0, yB = 0, zB = 0; // Ponto B - canto inferior esquerdo
    float xC = 0, yC = 0, zC = 0; // Ponto C - canto superior direito
    float xD = 0, yD = 0, zD = 0; // Ponto D - canto inferior direito

    float nxA = 0, nyA = 0, nzA = 0; // Ponto A - canto superior esquerdo
    float nxB = 0, nyB = 0, nzB = 0; // Ponto B - canto inferior esquerdo
    float nxC = 0, nyC = 0, nzC = 0; // Ponto C - canto superior direito
    float nxD = 0, nyD = 0, nzD = 0; // Ponto D - canto inferior direito

    float txA = 0, tyA = 0; // Ponto A - canto superior esquerdo
    float txB = 0, tyB = 0; // Ponto B - canto inferior esquerdo
    float txC = 0, tyC = 0; // Ponto C - canto superior direito
    float txD = 0, tyD = 0; // Ponto D - canto inferior direito

    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < stacks; i++)
        {
            for (int j = 0; j < slices; j++)
            {

                alpha = j * deslocacao_alpha;

                /* --------------------------------- Ponto A --------------------------------- */

                xA = radius * cos(beta + deslocacao_beta) * sin(alpha);
                yA = radius * sin(beta + deslocacao_beta);
                zA = radius * cos(beta + deslocacao_beta) * cos(alpha);

                nxA = cos(beta + deslocacao_beta) * sin(alpha);
                nyA = sin(beta + deslocacao_beta);
                nzA = cos(beta + deslocacao_beta) * cos(alpha);

                txA = j * texture_slices_step;
                tyA = (i + 1) * texture_stacks_step;

                /* --------------------------------- Ponto B --------------------------------- */

                xB = radius * cos(beta) * sin(alpha);
                yB = radius * sin(beta);
                zB = radius * cos(beta) * cos(alpha);

                nxB = cos(beta) * sin(alpha);
                nyB = sin(beta);
                nzB = cos(beta) * cos(alpha);

                txB = j * texture_slices_step;
                tyB = i * texture_stacks_step;

                /* --------------------------------- Ponto C --------------------------------- */

                xC = radius * cos(beta + deslocacao_beta) * sin(alpha + deslocacao_alpha);
                yC = radius * sin(beta + deslocacao_beta);
                zC = radius * cos(beta + deslocacao_beta) * cos(alpha + deslocacao_alpha);

                nxC = cos(beta + deslocacao_beta) * sin(alpha + deslocacao_alpha);
                nyC = sin(beta + deslocacao_beta);
                nzC = cos(beta + deslocacao_beta) * cos(alpha + deslocacao_alpha);

                txC = (j + 1) * texture_slices_step;
                tyC = (i + 1) * texture_stacks_step;

                /* --------------------------------- Ponto D --------------------------------- */

                xD = radius * cos(beta) * sin(alpha + deslocacao_alpha);
                yD = radius * sin(beta);
                zD = radius * cos(beta) * cos(alpha + deslocacao_alpha);

                nxD = cos(beta) * sin(alpha + deslocacao_alpha);
                nyD = sin(beta);
                nzD = cos(beta) * cos(alpha + deslocacao_alpha);

                txD = (j + 1) * texture_slices_step;
                tyD = (i)*texture_stacks_step;

                /* ----------------------------------- C - A - B ------------------------------------ */

                file << "" << xC << " " << yC << " " << zC << endl;
                file << "" << nxC << " " << nyC << " " << nzC << endl;
                file << "" << txC << " " << tyC << endl;

                file << "" << xA << " " << yA << " " << zA << endl;
                file << "" << nxA << " " << nyA << " " << nzA << endl;
                file << "" << txA << " " << tyA << endl;

                file << "" << xB << " " << yB << " " << zB << endl;
                file << "" << nxB << " " << nyB << " " << nzB << endl;
                file << "" << txB << " " << tyB << endl;

                /* ----------------------------------- B - D - C -------------------------------- */

                file << "" << xB << " " << yB << " " << zB << endl;
                file << "" << nxB << " " << nyB << " " << nzB << endl;
                file << "" << txB << " " << tyB << endl;

                file << "" << xD << " " << yD << " " << zD << endl;
                file << "" << nxD << " " << nyD << " " << nzD << endl;
                file << "" << txD << " " << tyD << endl;

                file << "" << xC << " " << yC << " " << zC << endl;
                file << "" << nxC << " " << nyC << " " << nzC << endl;
                file << "" << txC << " " << tyC << endl;
            }
            beta += deslocacao_beta;
        }
    }
    file.close();
}
void drawCone(float radius, float height, int slices, int stacks, string filename)
{

    float angle = 0; // Ângulo ao centro
    float alfa = (2 * M_PI) / ((float)slices);
    float diffRadius = radius / stacks; // Diferença entre valores de raio de cada stack

    // Coordenadas de referência
    float lowerR = 0; // Raio do círculo dos 2 pontos inferiores
    float upperR = 0; // Raio do círculo dos 2 pontos superiores

    // Pontos de referência para aplicar-se a regra da mão direita
    float xA, yA, zA; //Ponto A - canto inferior esquerdo
    float xB, yB, zB; //Ponto B - canto inferior direito
    float xC, yC, zC; //Ponto C - canto superior direito
    float xD, yD, zD; //Ponto D - canto superior esquerdo

    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < stacks; i++)
        {

            lowerR = radius - diffRadius * i;
            upperR = radius - diffRadius * (i + 1);

            // Percorrem-se as slices e calculam-se as coordenadas
            // dos pontos de referência para a stack e slice atuais
            for (int j = 0; j < slices; j++)
            {
                angle = alfa * j;

                // Cálculo das novas coordenadas do ponto A
                xA = lowerR * sin(angle);
                yA = i * height / stacks;
                zA = lowerR * cos(angle);

                // Cálculo das novas coordenadas do ponto B
                xB = lowerR * sin(angle + alfa);
                yB = i * height / stacks;
                zB = lowerR * cos(angle + alfa);

                // Cálculo das novas coordenadas do ponto C
                xC = upperR * sin(angle + alfa);
                yC = (i + 1) * height / stacks;
                zC = upperR * cos(angle + alfa);

                // Cálculo das novas coordenadas do ponto D
                xD = upperR * sin(angle);
                yD = (i + 1) * height / stacks;
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

        for (int i = 0; i < slices; i++)
        {
            file << ""
                 << "0"
                 << " "
                 << "0"
                 << " "
                 << "0"
                 << "\n";
            file << "" << radius * sin(alfa * i) << " "
                 << "0"
                 << " " << radius * cos(alfa * i) << "\n";
            file << "" << radius * sin(alfa * (i + 1)) << " "
                 << "0"
                 << " " << radius * cos(alfa * (i + 1)) << "\n";
        }
    }
    file.close();
}

void drawTorus(float ri, float re, int slices, int stacks, string filename) {
    float alpha = 0;
    float beta = 0;

    int i = 0;
    int j = 0;

    float textureStack = float(1) / stacks;
    float textureSlice = float(1) / slices;

    float desAlpha = (2 * M_PI) / stacks;
    float desBeta = (2 * M_PI) / slices;

    float xA, yA, zA;
    float xB, yB, zB;
    float xC, yC, zC;
    float xD, yD, zD;
    float xE, yE, zE;
    float xF, yF, zF;
    float xG, yG, zG;
    float xH, yH, zH;

    float nxA = 0, nyA = 0, nzA = 0;   // Ponto A 
    float nxB = 0, nyB = 0, nzB = 0;   // Ponto B 
    float nxC = 0, nyC = 0, nzC = 0;   // Ponto C 
    float nxD = 0, nyD = 0, nzD = 0;   // Ponto D 
    float nxE = 0, nyE = 0, nzE = 0;   // Ponto E 
    float nxF = 0, nyF = 0, nzF = 0;   // Ponto F 
    float nxG = 0, nyG = 0, nzG = 0;   // Ponto G
    float nxH = 0, nyH = 0, nzH = 0;   // Ponto H 

    float txA = 0, tyA = 0;        // Ponto A 
    float txB = 0, tyB = 0;        // Ponto B 
    float txC = 0, tyC = 0;        // Ponto C 
    float txD = 0, tyD = 0;       // Ponto D
    float txE = 0, tyE = 0;       // Ponto E
    float txF = 0, tyF = 0;       // Ponto F
    float txG = 0, tyG = 0;       // Ponto G
    float txH = 0, tyH = 0;       // Ponto H

    ofstream file(filename);
    if (file.is_open()) {

        for (i = 0; i < stacks; i++) {

            xB = (re + ri * cos(beta)) * cos(alpha);
            yB = (re + ri * cos(beta)) * sin(alpha);
            zB = ri * sin(beta);

            nxB = cos(alpha) * cos(beta);
            nyB = cos(beta) * sin(alpha);
            nzB = sin(beta);

            txB = i * textureStack;
            tyB = j * textureSlice;

            xC = (re + ri * cos(beta)) * cos(alpha + desAlpha);
            yC = (re + ri * cos(beta)) * sin(alpha + desAlpha);
            zC = ri * sin(beta); 

            nxC = cos(beta) * cos(alpha + desAlpha);
            nyC = cos(beta) * sin(alpha + desAlpha);
            nzC = sin(beta);

            txC = (i + 1) * textureStack;
            tyC = j * textureSlice;

            xA = (re + ri * cos(beta + M_PI)) * cos(alpha);
            yA = (re + ri * cos(beta + M_PI)) * sin(alpha);
            zA = ri * sin(beta + M_PI); 

            nxA = cos(beta + M_PI) * cos(alpha);
            nyA = cos(beta + M_PI) * sin(alpha);
            nzA = sin(beta + M_PI);

            txA = i * textureStack;
            tyA = (j + 0.5) * textureSlice;

            xD = (re + ri * cos(beta + M_PI)) * cos(alpha + desAlpha);
            yD = (re + ri * cos(beta + M_PI)) * sin(alpha + desAlpha);
            zD = ri * sin(beta + M_PI);

            nxD = cos(beta + M_PI) * cos(alpha + desAlpha);
            nyD = cos(beta + M_PI) * sin(alpha + desAlpha);
            nzD = sin(beta + M_PI);

            txD = (i + 1) * textureStack;
            tyD = (j + 0.5) * textureSlice;

            file << "" << xB << " " << yB << " " << zB << endl;
            file << "" << nxB << " " << nyB << " " << nzB << endl;
            file << "" << txB << " " << tyB << endl;

            file << "" << xC << " " << yC << " " << zC << endl;
            file << "" << nxC << " " << nyC << " " << nzC << endl;
            file << "" << txC << " " << tyC << endl;

            file << "" << xA << " " << yA << " " << zA << endl;
            file << "" << nxA << " " << nyA << " " << nzA << endl;
            file << "" << txA << " " << tyA << endl;

            file << "" << xA << " " << yA << " " << zA << endl;
            file << "" << nxA << " " << nyA << " " << nzA << endl;
            file << "" << txA << " " << tyA << endl;

            file << "" << xC << " " << yC << " " << zC << endl;
            file << "" << nxC << " " << nyC << " " << nzC << endl;
            file << "" << txC << " " << tyC << endl;

            file << "" << xD << " " << yD << " " << zD << endl;
            file << "" << nxD << " " << nyD << " " << nzD << endl;
            file << "" << txD << " " << tyD << endl;


            for (j = 0; j < slices; j++) {

                xB = (re + ri * cos(beta)) * cos(alpha);
                yB = (re + ri * cos(beta)) * sin(alpha);
                zB = ri * sin(beta); 

                nxB = cos(alpha) * cos(beta);
                nyB = cos(beta) * sin(alpha);
                nzB = sin(beta);

                txB = i * textureStack;
                tyB = j * textureSlice;

                xF = (re + ri * cos(beta + desBeta)) * cos(alpha + desAlpha);
                yF = (re + ri * cos(beta + desBeta)) * sin(alpha + desAlpha);
                zF = ri * sin(beta + desBeta);

                nxF = cos(beta + desBeta) * cos(alpha + desAlpha);
                nyF = cos(beta + desBeta) * sin(alpha + desAlpha);
                nzF = sin(beta + desBeta);

                txF = (i + 1) * textureStack;
                tyF = (j + 1) * textureSlice;

                xE = (re + ri * cos(beta + desBeta)) * cos(alpha);
                yE = (re + ri * cos(beta + desBeta)) * sin(alpha);
                zE = ri * sin(beta + desBeta);

                nxE = cos(beta + desBeta) * cos(alpha);
                nyE = cos(beta + desBeta) * sin(alpha);
                nzE = sin(beta + desBeta);

                txE = i * textureStack;
                tyE = (j + 1) * textureSlice;

                xC = (re + ri * cos(beta)) * cos(alpha + desAlpha);
                yC = (re + ri * cos(beta)) * sin(alpha + desAlpha);
                zC = ri * sin(beta); 

                nxC = cos(beta) * cos(alpha + desAlpha);
                nyC = cos(beta) * sin(alpha + desAlpha);
                nzC = sin(beta);

                txC = (i + 1) * textureStack;
                tyC = (j) * textureSlice;

                xG = (re + ri * cos(beta - desBeta)) * cos(alpha);
                yG = (re + ri * cos(beta - desBeta)) * sin(alpha);
                zG = ri * sin(beta - desBeta); 

                nxG = cos(beta - desBeta) * cos(alpha);
                nyG = cos(beta - desBeta) * sin(alpha);
                nzG = sin(beta - desBeta);

                txG = i * textureStack;
                tyG = (j + 1) * textureSlice;

                xH = (re + ri * cos(beta - desBeta)) * cos(alpha + desAlpha);
                yH = (re + ri * cos(beta - desBeta)) * sin(alpha + desAlpha);
                zH = ri * sin(beta - desBeta);

                nxH = cos(beta - desBeta) * cos(alpha + desAlpha);
                nyH = cos(beta - desBeta) * sin(alpha + desAlpha);
                nzH = sin(beta - desBeta);
            
                txH = (i + 1) * textureStack;
                tyH = (j + 1) * textureSlice;

                file << "" << xB << " " << yB << " " << zB << endl;
                file << "" << nxB << " " << nyB << " " << nzB << endl;
                file << "" << txB << " " << tyB << endl;

                file << "" << xF << " " << yF << " " << zF << endl;
                file << "" << nxF << " " << nyF << " " << nzF << endl;
                file << "" << txF << " " << tyF << endl;

                file << "" << xE << " " << yE << " " << zE << endl;
                file << "" << nxE << " " << nyE << " " << nzE << endl;
                file << "" << txE << " " << tyE << endl;
                
                file << "" << xB << " " << yB << " " << zB << endl;
                file << "" << nxB << " " << nyB << " " << nzB << endl;
                file << "" << txB << " " << tyB << endl;

                file << "" << xG << " " << yG << " " << zG << endl;
                file << "" << nxG << " " << nyG << " " << nzG << endl;
                file << "" << txG << " " << tyG << endl;

                file << "" << xC << " " << yC << " " << zC << endl;
                file << "" << nxC << " " << nyC << " " << nzC << endl;
                file << "" << txC << " " << tyC << endl;

                file << "" << xC << " " << yC << " " << zC << endl;
                file << "" << nxC << " " << nyC << " " << nzC << endl;
                file << "" << txC << " " << tyC << endl;
            
                file << "" << xG << " " << yG << " " << zG << endl;
                file << "" << nxG << " " << nyG << " " << nzG << endl;
                file << "" << txG << " " << tyG << endl;

                file << "" << xH << " " << yH << " " << zH << endl;
                file << "" << nxH << " " << nyH << " " << nzH << endl;
                file << "" << txH << " " << tyH << endl;

                beta += desBeta;
            }
            alpha += desAlpha;
        }
    }
    file.close();
}


void generateBezierPatches(vector<int> &indices, vector<Ponto> &control_points, int numPatches, int tessellation, string fileToWrite)
{

    vector<Ponto> bezier_points;
    vector<Normal> bezier_normals;
    vector<Textura> bezier_textures;

    /* Cria vetor com os pontos do patch correspondente*/
    for (int patch = 0; patch < numPatches; patch++)
    {

        vector<Ponto> patch_points;

        float tess = (float)1 / (float)tessellation;

        for (int p = 0; p < INDEX_PER_PATCH; p++)
        {
            patch_points.push_back(control_points[indices[patch * INDEX_PER_PATCH + p]]);
        }

        /* Cria pontos para o patch correspondente */
        for (int i = 0; i < tessellation + 1; i++)
        {
            for (int j = 0; j < tessellation + 1; j++)
            {
                float u = i * tess;
                float v = j * tess;

                Ponto bezier_patch_point;
                Normal bezier_patch_normal;
                Textura bezier_patch_texture;

                bezier_patch_point = generateBezierPoint(patch_points, u, v);
                bezier_patch_normal = normalBezier(patch_points, u, v);
                bezier_patch_texture.x = u;
                bezier_patch_texture.y = v;
                bezier_points.push_back(bezier_patch_point);
                bezier_normals.push_back(bezier_patch_normal);
                bezier_textures.push_back(bezier_patch_texture);

                bezier_patch_point = generateBezierPoint(patch_points, u + tess, v);
                bezier_patch_normal = normalBezier(patch_points, u + tess, v);
                bezier_patch_texture.x = u + tess;
                bezier_patch_texture.y = v;
                bezier_points.push_back(bezier_patch_point);
                bezier_normals.push_back(bezier_patch_normal);
                bezier_textures.push_back(bezier_patch_texture);

                bezier_patch_point = generateBezierPoint(patch_points, u, v + tess);
                bezier_patch_normal = normalBezier(patch_points, u, v + tess);
                bezier_patch_texture.x = u;
                bezier_patch_texture.y = v + tess;
                bezier_points.push_back(bezier_patch_point);
                bezier_normals.push_back(bezier_patch_normal);
                bezier_textures.push_back(bezier_patch_texture);

                bezier_points.push_back(bezier_patch_point);
                bezier_normals.push_back(bezier_patch_normal);
                bezier_textures.push_back(bezier_patch_texture);

                bezier_patch_point = generateBezierPoint(patch_points, u + tess, v);
                bezier_patch_normal = normalBezier(patch_points, u + tess, v);
                bezier_patch_texture.x = u + tess;
                bezier_patch_texture.y = v;
                bezier_points.push_back(bezier_patch_point);
                bezier_normals.push_back(bezier_patch_normal);
                bezier_textures.push_back(bezier_patch_texture);

                bezier_patch_point = generateBezierPoint(patch_points, u + tess, v + tess);
                bezier_patch_normal = normalBezier(patch_points, u + tess, v + tess);
                bezier_patch_texture.x = u + tess;
                bezier_patch_texture.y = v + tess;
                bezier_points.push_back(bezier_patch_point);
                bezier_normals.push_back(bezier_patch_normal);
                bezier_textures.push_back(bezier_patch_texture);
            }
        }
    }
    /* Abertura do ficheiro para onde vai escrever os pontos */
    ofstream file(fileToWrite);

    if (file.is_open())
    {
        for (int i = 0; i < bezier_points.size(); i++)
        {
            file << bezier_points[i].x << " " << bezier_points[i].y << " " << bezier_points[i].z << endl;
            file << bezier_normals[i].x << " " << bezier_normals[i].y << " " << bezier_normals[i].z << endl;
            file << bezier_textures[i].x << " " << bezier_textures[i].y << endl;
        }
    }
    file.close();
}

void readBezierPatches(string fileName, int tessellation, string fileToWrite)
{

    ifstream infile;
    stringstream ss;
    string line;

    int indice = 0;
    int numPatches = 0;
    int numControlPoints = 0;
    int controlpoint = 0;
    int coord = 1;
    int linha = 0;

    bool firstLine = true;

    vector<int> indices;
    vector<Ponto> control_points;

    infile.open(fileName);

    if (infile.is_open())
    {

        /* Percorre linha a linha ate EOF */
        while (getline(infile, line))
        {

            stringstream ss(line);

            /* Retira o número de patches que se encontra na primeira linha */
            if (firstLine == true)
            {
                numPatches = stoi(line);
                firstLine = false;
            }

            /* Entra na zona onde estão indicados os índices dos patches*/
            if (linha >= 1 && linha <= numPatches)
            {
                string token;

                /* Coloca o índices dos patches no array índices e retira vírgulas */
                while (getline(ss, token, ','))
                {
                    stringstream tokenize(token);
                    tokenize >> indice;
                    indices.push_back(indice);
                }
            }

            /* Retira o número de Pontos de Controlo */
            if (linha == numPatches + 1)
                numControlPoints = stoi(line);

            /* Linhas que se econtram na zona de pontos de controlo  */
            if (linha > numPatches + 1 && controlpoint <= numControlPoints)
            {

                string token;

                /* Retira coordenadas do ponto de controlo */
                while (getline(ss, token, ','))
                {
                    Ponto p;

                    stringstream tokenize(token);

                    if (coord == 1)
                        tokenize >> p.x;
                    if (coord == 2)
                        tokenize >> p.y;
                    if (coord == 3)
                        tokenize >> p.z;

                    /* Adicionam-se as coordenadas ao vetor de vértices */
                    if (coord == 3)
                    {
                        control_points.push_back(p);
                        coord = 0;
                    }
                    coord++;
                }
                controlpoint++;
            }
            linha++; /* Linha do ficheiro em que se encontra */
        }
        infile.close();
        generateBezierPatches(indices, control_points, numPatches, tessellation, fileToWrite);
    }
}

int main(int argc, char **argv)
{

    /*  API:
        EXEMPLO:
        generator plane <x> <z> <plane.3d>
        generator cube <x> <y> <z> <divisoes> <cube.3d>
        generator sphere <r> <slices> <stacks> <sphere.3d>
        generator cone <r> <h> <slices> <stacks> <cone.3d>
        generator torus <ri> <re> <slices> <stacks> <torus.3d>
        generator teapot <ficheiro_patch> <tessellation> <nome ficheiro a escrever(.3d)> 
     */

    string prefix1 = "../../files/3d/";
    string prefix2 = "../../files/input_files/";
    string c;
    string a;

    if (argc == 5 && !strcmp(argv[1], "plane"))
    {
        a = prefix1 + argv[4];
        drawPlane(atof(argv[2]), atof(argv[3]), a);
    }
    else if (argc == 7 && !strcmp(argv[1], "cube"))
    {
        a = prefix1 + argv[6];
        drawCube(atof(argv[2]), atof(argv[3]), atof(argv[4]), atoi(argv[5]), a);
    }
    else if (argc == 6 && !strcmp(argv[1], "sphere"))
    {
        a = prefix1 + argv[5];
        drawSphere(atof(argv[2]), atoi(argv[3]), atoi(argv[4]), a);
    }
    else if (argc == 7 && !strcmp(argv[1], "cone"))
    {
        a = prefix1 + argv[6];
        drawCone(atof(argv[2]), atof(argv[3]), atoi(argv[4]), atoi(argv[5]), a);
    }
    else if (argc == 7 && !strcmp(argv[1], "torus"))
    {
        a = prefix1 + argv[6];
        drawTorus(atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), a);
    }
    else if (argc == 5 && !strcmp(argv[1], "teapot"))
    {
        a = prefix1 + argv[4];
        c = prefix2 + argv[2];
        readBezierPatches(c, atoi(argv[3]), a);
    }

    return 1;
}
