#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "../include/Ponto.h"

constexpr auto INDEX_PER_PATCH = 16;

using namespace std;

void drawPlane(float x, float z, string filename) {

    ofstream file(filename);
    if (file.is_open()) {

        file << "" << (-x / 2) << " 0 " << (-z / 2) << "\n";
        file << "" << (-x / 2) << " 0 " << (z / 2) << "\n";
        file << "" << (x / 2) << " 0 " << (z / 2) << "\n";

        file << "" << (-x / 2) << " 0 " << (-z / 2) << "\n";
        file << "" << (x / 2) << " 0 " << (z / 2) << "\n";
        file << "" << (x / 2) << " 0 " << (-z / 2) << "\n";

        file << "" << (-x / 2) << " 0 " << (-z / 2) << "\n";
        file << "" << (x / 2) << " 0 " << (z / 2) << "\n";
        file << "" << (-x / 2) << " 0 " << (z / 2) << "\n";

        file << "" << (-x / 2) << " 0 " << (-z / 2) << "\n";
        file << "" << (x / 2) << " 0 " << (-z / 2) << "\n";
        file << "" << (x / 2) << " 0 " << (z / 2) << "\n";

    }
    file.close();
}

void drawCube(float x, float y, float z, int d, string filename) {

    ofstream file(filename);
    if (file.is_open()) {
        float xShift = x / d;
        float yShift = y / d;
        float zShift = z / d;

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                for (int k = 0; k < d; k++) {

                    // face tras
                    file << "" << xShift * i << " " << yShift * j << " " << zShift * k << "\n";
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * k << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * k << "\n";

                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * k << "\n";
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * k << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * k << "\n";

                    // face esquerda
                    file << "" << xShift * i << " " << yShift * j << " " << zShift * k << "\n";
                    file << "" << xShift * i << " " << yShift * j << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * k << "\n";

                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * k << "\n";
                    file << "" << xShift * i << " " << yShift * j << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";

                    // face baixo
                    file << "" << xShift * i << " " << yShift * j << " " << zShift * k << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * k << "\n";
                    file << "" << xShift * i << " " << yShift * j << " " << zShift * (k + 1) << "\n";

                    file << "" << xShift * i << " " << yShift * j << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * k << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * (k + 1) << "\n";

                    // face direita
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * k << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * k << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * (k + 1) << "\n";

                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * k << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";

                    // face frente
                    file << "" << xShift * i << " " << yShift * j << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";

                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * j << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";

                    // face cima
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * k << "\n";
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * k << "\n";

                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * k << "\n";
                    file << "" << xShift * i << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";
                    file << "" << xShift * (i + 1) << " " << yShift * (j + 1) << " " << zShift * (k + 1) << "\n";
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
    if (file.is_open()) {
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
void drawCone(float radius, float height, int slices, int stacks, string filename) {

    float angle = 0; // Ângulo ao centro
    float alfa = (2 * M_PI) / ((float)slices);
    float diffRadius = radius / stacks; // Diferença entre valores de raio de cada stack

    // Coordenadas de referência
    float lowerR = 0;        // Raio do círculo dos 2 pontos inferiores
    float upperR = 0;        // Raio do círculo dos 2 pontos superiores

    // Pontos de referência para aplicar-se a regra da mão direita
    float xA, yA, zA;        //Ponto A - canto inferior esquerdo
    float xB, yB, zB;        //Ponto B - canto inferior direito
    float xC, yC, zC;        //Ponto C - canto superior direito
    float xD, yD, zD;        //Ponto D - canto superior esquerdo

    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < stacks; i++) {

            lowerR = radius - diffRadius * i;
            upperR = radius - diffRadius * (i + 1);

            // Percorrem-se as slices e calculam-se as coordenadas
            // dos pontos de referência para a stack e slice atuais
            for (int j = 0; j < slices; j++) {
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

        for (int i = 0; i < slices; i++) {
            file << "" << "0" << " " << "0" << " " << "0" << "\n";
            file << "" << radius * sin(alfa * i) << " " << "0" << " " << radius * cos(alfa * i) << "\n";
            file << "" << radius * sin(alfa * (i + 1)) << " " << "0" << " " << radius * cos(alfa * (i + 1)) << "\n";
        }
    }
    file.close();
}

void drawTorus(float ri, float re, int slices, int stacks, string filename) {
    float alpha = 0;
    float beta = 0;

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

    ofstream file(filename);
    if (file.is_open()) {

        for (int i = 0; i < stacks; i++) {

            xB = (re + ri * cos(beta)) * cos(alpha);
            yB = (re + ri * cos(beta)) * sin(alpha);
            zB = ri * sin(beta); //B

            xC = (re + ri * cos(beta)) * cos(alpha + desAlpha);
            yC = (re + ri * cos(beta)) * sin(alpha + desAlpha);
            zC = ri * sin(beta); // C

            xA = (re + ri * cos(beta + M_PI)) * cos(alpha);
            yA = (re + ri * cos(beta + M_PI)) * sin(alpha);
            zA = ri * sin(beta + M_PI); // A

            file << "" << xB << " " << yB << " " << zB << endl;
            file << "" << xC << " " << yC << " " << zC << endl;
            file << "" << xA << " " << yA << " " << zA << endl;

            xA = (re + ri * cos(beta + M_PI)) * cos(alpha);
            yA = (re + ri * cos(beta + M_PI)) * sin(alpha);
            zA = ri * sin(beta + M_PI); // A

            xC = (re + ri * cos(beta)) * cos(alpha + desAlpha);
            yC = (re + ri * cos(beta)) * sin(alpha + desAlpha);
            zC = ri * sin(beta); // C

            xD = (re + ri * cos(beta + M_PI)) * cos(alpha + desAlpha);
            yD = (re + ri * cos(beta + M_PI)) * sin(alpha + desAlpha);
            zD = ri * sin(beta + M_PI); // D

            file << "" << xA << " " << yA << " " << zA << endl;
            file << "" << xC << " " << yC << " " << zC << endl;
            file << "" << xD << " " << yD << " " << zD << endl;


            for (int j = 0; j < slices; j++) {

                xB = (re + ri * cos(beta)) * cos(alpha);
                yB = (re + ri * cos(beta)) * sin(alpha);
                zB = ri * sin(beta); //B

                xF = (re + ri * cos(beta + desBeta)) * cos(alpha + desAlpha);
                yF = (re + ri * cos(beta + desBeta)) * sin(alpha + desAlpha);
                zF = ri * sin(beta + desBeta); // F

                xE = (re + ri * cos(beta + desBeta)) * cos(alpha);
                yE = (re + ri * cos(beta + desBeta)) * sin(alpha);
                zE = ri * sin(beta + desBeta); //E

                file << "" << xB << " " << yB << " " << zB << endl;
                file << "" << xF << " " << yF << " " << zF << endl;
                file << "" << xE << " " << yE << " " << zE << endl;


                xB = (re + ri * cos(beta)) * cos(alpha);
                yB = (re + ri * cos(beta)) * sin(alpha);
                zB = ri * sin(beta); //B

                xC = (re + ri * cos(beta)) * cos(alpha + desAlpha);
                yC = (re + ri * cos(beta)) * sin(alpha + desAlpha);
                zC = ri * sin(beta); // C

                xF = (re + ri * cos(beta + M_PI)) * cos(alpha);
                yF = (re + ri * cos(beta + M_PI)) * sin(alpha);
                zF = ri * sin(beta + M_PI); // F

                file << "" << xB << " " << yB << " " << zB << endl;
                file << "" << xC << " " << yC << " " << zC << endl;
                file << "" << xF << " " << yF << " " << zF << endl;


                xB = (re + ri * cos(beta)) * cos(alpha);
                yB = (re + ri * cos(beta)) * sin(alpha);
                zB = ri * sin(beta); //B

                xG = (re + ri * cos(beta - desBeta)) * cos(alpha);
                yG = (re + ri * cos(beta - desBeta)) * sin(alpha);
                zG = ri * sin(beta - desBeta); //G

                xC = (re + ri * cos(beta)) * cos(alpha + desAlpha);
                yC = (re + ri * cos(beta)) * sin(alpha + desAlpha);
                zC = ri * sin(beta); // C

                file << "" << xB << " " << yB << " " << zB << endl;
                file << "" << xG << " " << yG << " " << zG << endl;
                file << "" << xC << " " << yC << " " << zC << endl;

                xC = (re + ri * cos(beta)) * cos(alpha + desAlpha);
                yC = (re + ri * cos(beta)) * sin(alpha + desAlpha);
                zC = ri * sin(beta); // C

                xG = (re + ri * cos(beta - desBeta)) * cos(alpha);
                yG = (re + ri * cos(beta - desBeta)) * sin(alpha);
                zG = ri * sin(beta - desBeta); //G

                xH = (re + ri * cos(beta - desBeta)) * cos(alpha + desAlpha);
                yH = (re + ri * cos(beta - desBeta)) * sin(alpha + desAlpha);
                zH = ri * sin(beta - desBeta); // H

                file << "" << xC << " " << yC << " " << zC << endl;
                file << "" << xG << " " << yG << " " << zG << endl;
                file << "" << xH << " " << yH << " " << zH << endl;

                beta += desBeta;
            }
            alpha += desAlpha;
        }
    }
    file.close();
}

void multMatrixVector(float* m, float* v, float* res) {

    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }
}

Ponto generateBezierPoint(vector<Ponto>& patch_points, float u, float v) {

    float M[16] = { -1, 3, -3, 1, 3, -6, 3, 0, -3, 3, 0, 0, 1, 0, 0, 0 };

    float U[4] = { u * u * u, u * u, u, 1 };
    float V[4] = { v * v * v, v * v, v, 1 };

    float UM[4];
    float MV[4];
    //3 -> x,y,z
    float UMPontos[3][4];
    float PontoBezier[3];

    Ponto pontoGerado;

    //U x M
    multMatrixVector(M, U, UM);
    //M x V
    multMatrixVector(M, V, MV);
    
    for (int j = 0; j < 4; j++) {
        UMPontos[0][j] = UM[0] * patch_points[j * 4 + 0].x + UM[1] * patch_points[j * 4 + 1].x
            + UM[2] * patch_points[j * 4 + 2].x + UM[3] * patch_points[j * 4 + 3].x;
        UMPontos[1][j] = UM[0] * patch_points[j * 4 + 0].y + UM[1] * patch_points[j * 4 + 1].y
            + UM[2] * patch_points[j * 4 + 2].y + UM[3] * patch_points[j * 4 + 3].y;
        UMPontos[2][j] = UM[0] * patch_points[j * 4 + 0].z + UM[1] * patch_points[j * 4 + 1].z
            + UM[2] * patch_points[j * 4 + 2].z + UM[3] * patch_points[j * 4 + 3].z;
    }

    //UMcoordenadasXYZ x MV
    for (int i = 0; i < 3; i++) {
        PontoBezier[i] = UMPontos[i][0] * MV[0] + UMPontos[i][1] * MV[1] + UMPontos[i][2] * MV[2] + UMPontos[i][3] * MV[3];
    }

    pontoGerado.x = PontoBezier[0]; pontoGerado.y = PontoBezier[1]; pontoGerado.z = PontoBezier[2];

    return pontoGerado;
}

void generateBezierPatches(vector<int>& indices, vector<Ponto>& control_points, int numPatches, int tessellation, string fileToWrite) {

    vector<Ponto> bezier_points;

    /* Cria vetor com os pontos do patch correspondente*/
    for (int patch = 0; patch < numPatches; patch++) {

        vector<Ponto> patch_points;

        float tess = (float)1 / (float)tessellation;

        for (int p = 0; p < INDEX_PER_PATCH; p++) {
            patch_points.push_back(control_points[indices[patch * INDEX_PER_PATCH + p]]);
        }

        /* Cria pontos para o patch correspondente */
        for (int i = 0; i < tessellation + 1; i++) {
            for (int j = 0; j < tessellation + 1; j++) {
                float u = i * tess;
                float v = j * tess;

                Ponto bezier_patch_point;

                bezier_patch_point = generateBezierPoint(patch_points, u, v);
                bezier_points.push_back(bezier_patch_point);
                bezier_patch_point = generateBezierPoint(patch_points, u + tess, v);
                bezier_points.push_back(bezier_patch_point);
                bezier_patch_point = generateBezierPoint(patch_points, u, v + tess);
                bezier_points.push_back(bezier_patch_point);
                bezier_points.push_back(bezier_patch_point);
                bezier_patch_point = generateBezierPoint(patch_points, u + tess, v);
                bezier_points.push_back(bezier_patch_point);
                bezier_patch_point = generateBezierPoint(patch_points, u + tess, v + tess);
                bezier_points.push_back(bezier_patch_point);
            }
        }
    }
    /* Abertura do ficheiro para onde vai escrever os pontos */
    ofstream file(fileToWrite);
   
    if (file.is_open()) {
        for (Ponto p : bezier_points) {
            file << p.x << " " << p.y << " " << p.z << endl;
        }
    }
    file.close();
}


void readBezierPatches(string fileName, int tessellation, string fileToWrite) {

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

    if (infile.is_open()) {
    
        /* Percorre linha a linha ate EOF */
        while (getline(infile, line)) {

            stringstream ss(line);

            /* Retira o número de patches que se encontra na primeira linha */
            if (firstLine == true) {
                numPatches = stoi(line);
                firstLine = false;
            }

            /* Entra na zona onde estão indicados os índices dos patches*/
            if (linha >= 1 && linha <= numPatches) {
                string token;

                /* Coloca o índices dos patches no array índices e retira vírgulas */
                while (getline(ss, token, ',')) {
                    stringstream tokenize(token);
                    tokenize >> indice;
                    indices.push_back(indice);
                }
            }

            /* Retira o número de Pontos de Controlo */
            if (linha == numPatches + 1) 
                numControlPoints = stoi(line);
              
            /* Linhas que se econtram na zona de pontos de controlo  */
            if (linha > numPatches + 1 && controlpoint <= numControlPoints) {
                
                string token;

                /* Retira coordenadas do ponto de controlo */
                while (getline(ss, token, ',')) {
                    Ponto p;

                    stringstream tokenize(token);

                    if (coord == 1)  tokenize >> p.x;
                    if (coord == 2)  tokenize >> p.y;
                    if (coord == 3)  tokenize >> p.z;

                    /* Adicionam-se as coordenadas ao vetor de vértices */
                    if (coord == 3) {
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


int main(int argc, char** argv) {


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

    if (argc == 5 && !strcmp(argv[1], "plane")) {
        a = prefix1 + argv[4];
        drawPlane(atof(argv[2]), atof(argv[3]), a);
    }
    else if (argc == 7 && !strcmp(argv[1], "cube")) {
        a = prefix1 + argv[6];
        drawCube(atof(argv[2]), atof(argv[3]), atof(argv[4]), atoi(argv[5]), a);
    }
    else if (argc == 6 && !strcmp(argv[1], "sphere")) {
        a = prefix1 + argv[5];
        drawSphere(atof(argv[2]), atoi(argv[3]), atoi(argv[4]), a);
    }
    else if (argc == 7 && !strcmp(argv[1], "cone")) {
        a = prefix1 + argv[6];
        drawCone(atof(argv[2]), atof(argv[3]), atoi(argv[4]), atoi(argv[5]), a);
    }
    else if (argc == 7 && !strcmp(argv[1], "torus")) {
        a = x + argv[6];
        drawTorus(atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), a);
    }
    else if (argc == 5 && !strcmp(argv[1], "teapot")) {
        a = x + argv[4];
        c = prefix2 + argv[2];
        readBezierPatches(c, atoi(argv[3]), a);
    }

    return 1;
}
