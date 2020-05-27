#include "headers/Model.h"

Model::Model(int texFlag, VBO v, string texture, float *amb, float *diff, float * spec, float *emiss, float shin) {
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
    this->v = v;
}

void Model:: setTexture(string texture){
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
    /*Primitive primitive_to_draw = PrimitiveMap.at(primitive);
    GLuint texture_to_draw;

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_EMISSION, emissive);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);


    glBindBuffer(GL_ARRAY_BUFFER, primitive_to_draw.vertex);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, primitive_to_draw.normals);
    glNormalPointer(GL_FLOAT, 0, 0);
    if(texFlag == 1){
        texture_to_draw = TextureMap.at(texture);
        glBindTexture(GL_TEXTURE_2D, texture_to_draw);
        glBindBuffer(GL_ARRAY_BUFFER, primitive_to_draw.texCoord);
        glTexCoordPointer(2, GL_FLOAT, 0, 0);
    }
    //  Draw
    glDrawArrays(GL_TRIANGLES, 0, (primitive_to_draw.vertexNumber / 3));
    glBindTexture(GL_TEXTURE_2D, 0);*/
}
