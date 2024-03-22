#include "vbo.h"

Vbo getVBO(GLint type, GLboolean dynamic){
    Vbo vbo = {0};
    vbo.dynamic = dynamic;
    vbo.type = type;
    glGenBuffers(1, &vbo.handle);
    return vbo;
}

void bindVBO(Vbo vbo){
    glBindBuffer(vbo.type, vbo.handle);
}

void destroyVBO(Vbo vbo){
    glDeleteBuffers(1, &vbo.handle);
}

void setVBOBuffer(Vbo vbo, void *data, size_t size){
    bindVBO(vbo);
    glBufferData(vbo.type, size, data, vbo.dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}