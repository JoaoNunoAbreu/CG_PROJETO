#include "headers/Grupo.h"
#include <iostream>

void Grupo :: drawGroup(float tempo){
    glPushMatrix();
    for (auto& transformation : transformations) { transformation->transform(tempo); }
    for (auto const &model : models) draw(model);
    for (auto &child : childgroups) child.drawGroup(tempo);
    glPopMatrix();
}

void Grupo :: draw(Model models){
    
    // cout << "GLuint " <<models.vertices<< endl;
    // cout << "Nº vert " << models.size << endl;
    //Desenha VBO
    
    /*glBindBuffer(GL_ARRAY_BUFFER, models.vertices);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, models.size_vertices);*/
}

void Grupo :: addTransformation(Transformacao* t){
    transformations.push_back(t);
}

void Grupo :: addModel(Model v){
    models.push_back(v);
}

void Grupo :: addChilds(Grupo t){
    childgroups.push_back(t);
}
