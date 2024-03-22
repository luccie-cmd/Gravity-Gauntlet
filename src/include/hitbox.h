#if !defined(_GRAVITY_GAUNTLET_HITBOX_)
#define _GRAVITY_GAUNTLET_HITBOX_
#include "types.h"

class HitBox{
    private:
        Vector2 pos;
        Vector2 size;
    public:
        HitBox(Vector2 pos, Vector2 size){
            this->pos = pos;
            this->size = size;
        }
        Vector2 get_pos() { return pos; };
        Vector2 get_size() { return size; };
        bool collides(int x, int y, int w, int h){
            // Calculate the minimum and maximum coordinates of both HitBoxes on both axes
            float aMinX = this->pos.x;
            float aMaxX = this->pos.x + this->size.x;
            float aMinY = this->pos.y;
            float aMaxY = this->pos.y + this->size.y;

            float bMinX = x;
            float bMaxX = x + w;
            float bMinY = y;
            float bMaxY = y + h;

            // Check for overlap on both axes
            bool overlapX = aMinX < bMaxX && aMaxX > bMinX;
            bool overlapY = aMinY < bMaxY && aMaxY > bMinY;

            // If there's overlap on both axes, there's a collision
            return overlapX && overlapY;
        }
};

#endif // _GRAVITY_GAUNTLET_HITBOX_
