#if !defined(_GRAVITY_GAUNTLET_VAO_)
#define _GRAVITY_GAUNTLET_VAO_
#include <stddef.h>
#include "glad/glad.h"
#include "vbo.h"

typedef struct{
    GLuint handle;
} Vao;

Vao getVAO();
void bindVAO(Vao vao);
void destroyVAO(Vao vao);
void setVAOAttrib(Vao vao, Vbo vbo, GLuint index, GLint size, GLenum type, GLsizei stride, size_t offset);

#endif // _GRAVITY_GAUNTLET_VAO_
