#if !defined(_GRAVITY_GAUNTLET_VBO_)
#define _GRAVITY_GAUNTLET_VBO_
#include <stddef.h>
#include "glad/glad.h"

typedef struct{
    GLuint handle;
    GLint type;
    GLboolean dynamic;
} Vbo;

Vbo getVBO(GLint type, GLboolean dynamic);
void bindVBO(Vbo vbo);
void destroyVBO(Vbo vbo);
void setVBOBuffer(Vbo vbo, void *data, size_t size);

#endif // _GRAVITY_GAUNTLET_VBO_
