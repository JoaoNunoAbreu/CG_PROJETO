#include "headers/Model.h"

Model::Model(VBO v) {
    Model::texFlag = 0;
    Model::texture = 0;
    Model::v = v;
    Model::ambient[0] = 0; Model::ambient[1] = 0; Model::ambient[2] = 0; Model::ambient[3] = 0;
    Model::diffuse[0] = 0; Model::diffuse[1] = 0; Model::diffuse[2] = 0; Model::diffuse[3] = 0;
    Model::specular[0] = 0; Model::specular[1] = 0; Model::specular[2] = 0; Model::specular[3] = 0;
    Model::emissive[0] = 0; Model::emissive[1] = 0; Model::emissive[2] = 0; Model::emissive[3] = 0;
    Model::shininess = 0;
}

Model::Model(int texFlag, VBO v, GLuint texture, float *amb, float *diff, float * spec, float *emiss, float shin) {
    Model::texFlag = texFlag;
    if(texFlag == 1)
        Model::texture = texture;
    Model::v = v;
    Model::ambient[0] = amb[0]; Model::ambient[1] = amb[1]; Model::ambient[2] = amb[2]; Model::ambient[3] = amb[3];
    Model::diffuse[0] = diff[0]; Model::diffuse[1] = diff[1]; Model::diffuse[2] = diff[2]; Model::diffuse[3] = diff[3];
    Model::specular[0] = spec[0]; Model::specular[1] = spec[1]; Model::specular[2] = spec[2]; Model::specular[3] = spec[3];
    Model::emissive[0] = emiss[0]; Model::emissive[1] = emiss[1]; Model::emissive[2] = emiss[2]; Model::emissive[3] = emiss[3];
    Model::shininess = shin;
}

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

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, emissive);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    glBindBuffer(GL_ARRAY_BUFFER, v.vertices);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, v.normals);
    glNormalPointer(GL_FLOAT, 0, 0);
    if(texFlag == 1){
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindBuffer(GL_ARRAY_BUFFER, v.texCoords);
        glTexCoordPointer(2, GL_FLOAT, 0, 0);
    }
    //  Draw
    glDrawArrays(GL_TRIANGLES, 0, (v.size_vertices));
    glBindTexture(GL_TEXTURE_2D, 0);
}
