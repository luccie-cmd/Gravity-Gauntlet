#include "vao.h"
#include "vbo.h"

Vao getVAO(){
    Vao vao = {0};
    glGenVertexArrays(1, &vao.handle);
    return vao;
}

void bindVAO(Vao vao){
    glBindVertexArray(vao.handle);
}

void destroyVAO(Vao vao){
    glDeleteVertexArrays(1, &vao.handle);
}

void setVAOAttrib(Vao vao, Vbo vbo, GLuint index, GLint size, GLenum type, GLsizei stride, size_t offset){
    bindVAO(vao);
    bindVBO(vbo);
    switch (type) {
        case GL_BYTE:
        case GL_UNSIGNED_BYTE:
        case GL_SHORT:
        case GL_UNSIGNED_SHORT:
        case GL_INT:
        case GL_UNSIGNED_INT:
        case GL_INT_2_10_10_10_REV:
        case GL_UNSIGNED_INT_2_10_10_10_REV:
            glVertexAttribIPointer(index, size, type, stride, (void *) offset);
            break;
        default:
            glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void *) offset);
            break;
    }
    glEnableVertexAttribArray(index);
}