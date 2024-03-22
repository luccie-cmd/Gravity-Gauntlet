#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "utils.h"

char* readFile(const char* name){
    FILE* f = fopen(name, "rb");
    if(!f){
        printf("Error: %s: %s\n", name, strerror(errno));
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    size_t size = (size_t)ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buffer = (char*)malloc(size+1);
    if(!buffer){
        printf("Error: %s: %s\n", name, strerror(errno));
        exit(1);
    }
    size_t read = fread(buffer, 1, size, f);
    if(read == 0){
        printf("Couldn't read file\n");
        exit(1);
    }
    fclose(f);
    buffer[size] = '\0';
    return buffer;
}