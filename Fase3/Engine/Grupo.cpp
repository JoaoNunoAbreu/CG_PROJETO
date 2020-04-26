#include "headers/Grupo.h"
#include <iostream>

void Grupo :: drawGroup(){
    glPushMatrix();
    for (auto &transformation : transformations) transformation->transform();
    for (auto const &model : models) draw(model);
    for (auto &child : childgroups) child.drawGroup();
    glPopMatrix();
}

void Grupo :: draw(VBO models){
    
   // cout << "GLuint " <<models.vertices<< endl;
    // cout << "Nº vert " << models.size << endl;
    glBindBuffer(GL_ARRAY_BUFFER, models.vertices);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, models.size);
}

void Grupo :: addTransformation(Transformacao* t){
    transformations.push_back(t);
}

void Grupo :: addModel(VBO v){
    models.push_back(v);
}

void Grupo :: addChilds(Grupo t){
    childgroups.push_back(t);
}