#if !defined(_GRAVITY_GAUNTLET_BUTTON_)
#define _GRAVITY_GAUNTLET_BUTTON_
#include "hitbox.h"
#include "renderer.h"

class Button{
    private:
        HitBox hitbox;
        Color draw_color;
    public:
        Button(void (*action)(int, ...), Vector2 pos, Vector2 size, Color color) :hitbox(HitBox(pos, size)), draw_color(color){
            this->action = action;
            this->hitbox = HitBox(pos, size);
            this->draw_color = color;
        }
        bool checkIfPressed(int mouseX, int mouseY);
        void draw(Renderer renderer);
        // Every button action is passed in via the constructor
        void (*action)(int, ...);
};

#endif // _GRAVITY_GAUNTLET_BUTTON_
