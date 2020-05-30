#include "headers/Grupo.h"
#include <iostream>

void Grupo :: drawGroup(float tempo){
    glPushMatrix();
    for (auto &transformation : transformations) { transformation->transform(tempo); }
    for (auto &model : models) model->drawModel();
    for (auto &child : childgroups) child.drawGroup(tempo);
    glPopMatrix();
}


void Grupo :: addTransformation(Transformacao* t){
    transformations.push_back(t);
}

void Grupo :: addModel(Model* v){
    models.push_back(v);
}

void Grupo :: addChilds(Grupo t){
    childgroups.push_back(t);
}
