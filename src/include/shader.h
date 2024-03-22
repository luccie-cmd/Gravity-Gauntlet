#if !defined(_GRAVITY_GAUNTLET_SHADER_)
#define _GRAVITY_GAUNTLET_SHADER_
#include "glad/glad.h"

class Shader{
    private:
        GLuint load_sub_shader(GLenum type, const char* src);
        GLuint save; // This is used so when we init the shader we "make" it and when we call activate we just activate this part
    public:
        Shader(const char* vertexData, const char* fragmentData);
        void activate_shader();
        void destroy_shader();
};

#endif // _GRAVITY_GAUNTLET_SHADER_
