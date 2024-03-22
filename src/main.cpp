#include <stdio.h>
#include <vector>
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "glad/glad.h"
#include "renderer.h"
#include "utils.h"
#include "button.h"

void render_start_menu();
void render_level_select();
void render_level(int level); // This (eventually) gets it's own file and maybe even folder
void handle_level_events(SDL_Event evs);

typedef enum Render_Modes{
    RENDER_START_MENU,
    RENDER_LEVEL_SELECT_MENU,
    RENDER_LEVEL
} Render_Modes;

std::vector<Button> start_menu_buttons;
std::vector<Button> level_select_buttons;
Render_Modes render_mode;
Renderer renderer;
int current_level = -1;

void start_menu_button_action1(int none, ...){
    (void)none;
    render_mode = RENDER_LEVEL_SELECT_MENU;
}

void set_level(int level, ...){
    current_level = level;
    printf("Level = %d\n", current_level);
    render_mode = RENDER_LEVEL;
}

void init_buttons();
void init_buttons(){
    start_menu_buttons.push_back(Button(start_menu_button_action1, vector2(820, 500), vector2(300, 125), color(255, 255, 255, 255)));

    level_select_buttons.push_back(Button(set_level, vector2(100, 100), vector2(100, 100), color(255, 255, 255, 255)));
    // level_select_buttons.push_back(Button(set_level, vector2(300, 100), vector2(100, 100), color(255, 255, 255, 255)));
}

int main(){
    renderer.init();
    // LevelData level_data = {0};
    init_buttons();
    render_mode = RENDER_START_MENU;
    printf("Done with initing\n");

    int quit = 0;
    int wireframe = 0;
    while(!quit){
        SDL_Event evs = {0};
        while(SDL_PollEvent(&evs)){
            if(render_mode == RENDER_LEVEL){
                handle_level_events(evs);
            } else{
                switch(evs.type){
                    case SDL_QUIT: quit = 1; break;
                    case SDL_KEYDOWN: {
                        switch(evs.key.keysym.sym){
                            case SDLK_F2: {
                                wireframe = ~wireframe;
                            } break;
                        }
                    } break;
                    case SDL_MOUSEBUTTONDOWN: {
                        if(evs.button.button == SDL_BUTTON_LEFT){
                            switch(render_mode){
                                case RENDER_START_MENU: {
                                    size_t i = 1;
                                    for(Button button : start_menu_buttons){
                                        if(button.checkIfPressed(evs.button.x, evs.button.y)){
                                            button.action(i);
                                        }
                                        ++i;
                                    }
                                } break;
                                case RENDER_LEVEL_SELECT_MENU: {
                                    size_t i = 1;
                                    for(Button button : level_select_buttons){
                                        if(button.checkIfPressed(evs.button.x, evs.button.y)){
                                            button.action(i);
                                        }
                                        ++i;
                                    }
                                } break;
                            }
                        }
                    } break;
                }
            }
        }
        renderer.BeginDrawing();
        glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
        switch(render_mode){
            case RENDER_START_MENU: {
                render_start_menu();
            } break;
            case RENDER_LEVEL_SELECT_MENU: {
                render_level_select();
            } break;
            case RENDER_LEVEL: {
                render_level(current_level);
            } break;
        }
        renderer.EndDrawing();
    }
    return 0;
}

void render_start_menu(){
    for(Button button : start_menu_buttons){
        button.draw(renderer);
    }
}

void render_level_select(){
    for(Button button : level_select_buttons){
        button.draw(renderer);
    }
}

void render_level(int level){

}

void handle_level_events(SDL_Event evs){
    
}