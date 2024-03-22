#include "renderer.h"
#include "shader.h"
#include "utils.h"
#include "vao.h"
#include "vbo.h"
#include <stdio.h>

const char* color1_shader_vert = "#version 330 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "layout (location = 1) in vec4 aColor;"
                                "out vec4 frag_color;\n"
                                "void main(){\n"
                                "    gl_Position = vec4(aPos, 1.0);\n"
                                "    frag_color = aColor;\n"
                                "}";

const char* color1_shader_frag = "#version 330 core\n"
                                "in vec4 frag_color;\n"
                                "void main(){\n"
                                "    gl_FragColor = frag_color;\n"
                                "}";

static Vector2 switchToOpenGLCoords(Vector2 coords){
    Vector2 openGLVector;
    // Convert x coordinate
    openGLVector.x = (coords.x / 1920.0f) * 2.0f - 1.0f;
    // Convert y coordinate
    openGLVector.y = 1.0f - (coords.y / 1080.0f) * 2.0;
    return openGLVector;
}

void Renderer::RenderTriangle(Vector2 p1,Vector2 p2, Vector2 p3, Color color){
    Vector2 openglp1, openglp2, openglp3;
    openglp1 = switchToOpenGLCoords(p1);
    openglp2 = switchToOpenGLCoords(p2);
    openglp3 = switchToOpenGLCoords(p3);

    Shader shader(color1_shader_vert, color1_shader_frag);

    GLfloat vertices[] = {
        openglp1.x, openglp1.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        openglp2.x, openglp2.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        openglp3.x, openglp3.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
    };

    Vao vao = getVAO();
    Vbo vbo = getVBO(GL_ARRAY_BUFFER, GL_TRUE);

    bindVAO(vao);

    setVBOBuffer(vbo, vertices, sizeof(vertices));

    setVAOAttrib(vao, vbo, 0, 3, GL_FLOAT, 7*sizeof(float), 0);
    setVAOAttrib(vao, vbo, 1, 4, GL_FLOAT, 7*sizeof(float), 3*sizeof(float));

    shader.activate_shader();
    bindVAO(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::RenderQuad(Vector2 top_left, Vector2 bottom_right, Color color){
    Vector2 opengl_tl, opengl_br;
    opengl_tl = switchToOpenGLCoords(top_left);
    opengl_br = switchToOpenGLCoords(bottom_right);
    
    Shader shader(color1_shader_vert, color1_shader_frag);

    GLfloat vertices[] = {
        opengl_tl.x, opengl_tl.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        opengl_tl.x, opengl_br.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        opengl_br.x, opengl_tl.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
        opengl_br.x, opengl_br.y, 0.0f, (color.r/255.0f), (color.g/255.0f), (color.b/255.0f), (color.a/255.0f),
    };
    
    // Indices for vertices order
    GLuint indices[] = {
    	0, 1, 2, // Upper triangle
    	1, 2, 3 // Lower triangle
    };

    Vao vao = getVAO();
    Vbo vbo = getVBO(GL_ARRAY_BUFFER, GL_TRUE);
    Vbo ebo = getVBO(GL_ELEMENT_ARRAY_BUFFER, GL_TRUE);

    bindVAO(vao);

    setVBOBuffer(vbo, vertices, sizeof(vertices));
    setVBOBuffer(ebo, indices, sizeof(indices));
    setVAOAttrib(vao, vbo, 0, 3, GL_FLOAT, 7*sizeof(float), 0);
    setVAOAttrib(vao, vbo, 1, 4, GL_FLOAT, 7*sizeof(float), 3*sizeof(float));

    shader.activate_shader();
    bindVAO(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::BeginDrawing(){
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::EndDrawing(){
    SDL_GL_SwapWindow(window);
}

void Renderer::init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL Couldn't init reason: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    window = SDL_CreateWindow("Gravity Gauntlet", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if(window == nullptr){
        printf("SDL Couldn't make window reason: %s\n", SDL_GetError());
        exit(1);
    }
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (context == nullptr) {
        printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
        exit(1);
    }
    if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        exit(1);
    }
    glViewport(0, 0, 1920, 1080);
    printf("openGL Version: %s\n", (const char*) glGetString(GL_VERSION));
}

Renderer::Renderer(){
    window = nullptr;
}