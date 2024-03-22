#include <stdio.h>
#include <stdlib.h>
#include "shader.h"
#include "utils.h"

Shader::Shader(const char* vertexData, const char* fragmentData){
    save = glCreateProgram();
    GLuint vertShader = load_sub_shader(GL_VERTEX_SHADER, vertexData);
    GLuint fragShader = load_sub_shader(GL_FRAGMENT_SHADER, fragmentData);
    glAttachShader(save, vertShader);
    glAttachShader(save, fragShader);
    // Link the program
    glLinkProgram(save);
    // Don't save any of the shaders we just made that would just be a waste of space
    glDeleteShader(vertShader); 
    glDeleteShader(fragShader);
}

GLuint Shader::load_sub_shader(GLenum type, const char* src){
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);
    // Check vertex shader compilation
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::%s::COMPILATION_FAILED\n%s\n", type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT", infoLog);
        exit(1);
    }
    return shader;
}

void Shader::activate_shader(){
    glUseProgram(save);
}

void Shader::destroy_shader(){
    glDeleteShader(save);
}