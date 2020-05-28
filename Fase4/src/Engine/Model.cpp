#include "headers/Model.h"

void Model:: setTexFlag(int texFlag){
    this->texFlag = texFlag;
}

void Model:: setVBO(VBO v){
    this->v.size_vertices = v.size_vertices;
    this->v.vertices = v.vertices;
}

void Model:: setTexture(GLuint texture){
    this->texture = texture;
}

void Model:: setAmbient(float* ambient){
    for(int i = 0; i < 4; i++)
        this->ambient[i] = ambient[i];
}

void Model:: setDiffuse(float* diffuse){
    for(int i = 0; i < 4; i++)
        this->diffuse[i] = diffuse[i];
}

void Model:: setSpecular(float* specular){
    for(int i = 0; i < 4; i++)
        this->specular[i] = specular[i];
}

void Model:: setEmissive(float* emissive){
    for(int i = 0; i < 4; i++)
        this->emissive[i] = emissive[i];
}

void Model:: setShininess(float shininess){
    this->shininess = shininess;
}

void Model::drawModel() {

    cout << "size_vertices = " << v.size_vertices << endl;
    
    glBindBuffer(GL_ARRAY_BUFFER, v.vertices);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, v.size_vertices);
}
