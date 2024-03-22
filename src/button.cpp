#include "button.h"
#include "renderer.h"

bool Button::checkIfPressed(int mouseX, int mouseY){
    if(this->hitbox.collides(mouseX, mouseY, 10, 10)){
        return true;
    }
    return false;
}
void Button::draw(Renderer renderer){
    renderer.RenderQuad(this->hitbox.get_pos(), vector2_add(this->hitbox.get_pos(), this->hitbox.get_size()), draw_color);
}