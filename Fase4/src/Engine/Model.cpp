#include "headers/Model.h"

Model::Model(int texFlag, string primitive, string texture, float *amb, float *diff, float * spec, float *emiss, float shin) {
    Model::texFlag = texFlag;
    if(texFlag == 1)
        Model::texture = texture;
    Model::primitive = primitive;
    Model::ambient[0] = amb[0]; Model::ambient[1] = amb[1]; Model::ambient[2] = amb[2]; Model::ambient[3] = amb[3];
    Model::diffuse[0] = diff[0]; Model::diffuse[1] = diff[1]; Model::diffuse[2] = diff[2]; Model::diffuse[3] = diff[3];
    Model::specular[0] = spec[0]; Model::specular[1] = spec[1]; Model::specular[2] = spec[2]; Model::specular[3] = spec[3];
    Model::emissive[0] = emiss[0]; Model::emissive[1] = emiss[1]; Model::emissive[2] = emiss[2]; Model::emissive[3] = emiss[3];
    Model::shininess = shin;
}