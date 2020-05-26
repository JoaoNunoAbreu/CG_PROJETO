#include "headers/BezierPatch.h"

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

float* derivateUBezier(vector<Ponto>& patch_points, float u, float v,float* vector) {

    float M[16] = { -1, 3, -3, 1, 3, -6, 3, 0, -3, 3, 0, 0, 1, 0, 0, 0 };

    float U[4] = { 3 * u * u, 2 * u, 1, 0 };
    float V[4] = { v * v * v, v * v, v, 1 };

    float UM[4];
    float MV[4];
    //3 -> x,y,z
    float UMPontos[3][4];


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
        vector[i] = UMPontos[i][0] * MV[0] + UMPontos[i][1] * MV[1] + UMPontos[i][2] * MV[2] + UMPontos[i][3] * MV[3];
    }

    return vector;
}

float* derivateVBezier(vector<Ponto>& patch_points, float u, float v,float* vector) {

    float M[16] = { -1, 3, -3, 1, 3, -6, 3, 0, -3, 3, 0, 0, 1, 0, 0, 0 };

    float U[4] = { u * u * u, u * u, u, 1 };
    float V[4] = { 3 * v * v, 2 * v, 1, 0 };

    float UM[4];
    float MV[4];
    //3 -> x,y,z
    float UMPontos[3][4];
    

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
       vector[i] = UMPontos[i][0] * MV[0] + UMPontos[i][1] * MV[1] + UMPontos[i][2] * MV[2] + UMPontos[i][3] * MV[3];
    }

    return vector;
}

void cross(float* a, float* b, float* res) {

    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(float* a) {

    float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0] / l;
    a[1] = a[1] / l;
    a[2] = a[2] / l;
}

void pointToVector(Ponto a, float* ponto) {
    ponto[0] = a.x;
    ponto[1] = a.y;
    ponto[2] = a.z;
}

Normal normalBezier(vector<Ponto>& patch_points, float u, float v) {

    float* vetorU = new float[3];
    float* vetorV = new float[3];
    float* normal = new float[3];

    for(int i=0;i<3;i++){
        vetorU[i]=0.0f;
        vetorV[i]=0.0f;
        normal[i]=0.0f;
    }

    vetorU = derivateUBezier(patch_points, u, v,vetorU);
    vetorV = derivateVBezier(patch_points, u, v,vetorV);
    
    Normal res;

    // normaliza os vetores
    normalize(vetorU);
    normalize(vetorV);

    // calcula o produto vetorial
    cross(vetorU, vetorV, normal);

    // normaliza a normal
    normalize(normal);

    // passar para tipo normal
    res.x = normal[0];
    res.y = normal[1];
    res.z = normal[2];

    return res;

}