#include "headers/Grupo.h"

void Grupo :: drawGroup(){
    glPushMatrix();
    for (auto &transformation : transformations) transformation->transform();
    for (auto const &model : models) draw(model);
    for (auto &child : childgroups) child.drawGroup();
    glPopMatrix();
}

void Grupo :: draw(vector<Ponto> models){
    
    glBegin(GL_TRIANGLES);
        for(int i = 0; i < models.size(); i++) {
            glVertex3f(models[i].x, models[i].y, models[i].z);
        }
    glEnd();
}

void Grupo :: addTransformation(Transformacao* t){
    transformations.push_back(t);
}

void Grupo :: addModel(vector<Ponto> t){
    models.push_back(t);
}

void Grupo :: addChilds(Grupo t){
    childgroups.push_back(t);
}