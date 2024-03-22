#if !defined(_GRAVITY_GAUNTLET_TYPES_)
#define _GRAVITY_GAUNTLET_TYPES_

typedef struct{
    float x, y;
} Vector2;
#define VECTOR2_FMT "x: %f y: %f"
#define VECTOR2_ARG(V) V.x, V.y

typedef struct{
    int r, g, b, a;
} Color;

typedef enum{
    DIRECTION_NONE,
    DIRECTION_DOWN,
    DIRECTION_UP,
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
} Direction;

Vector2 vector2(float x, float y);
Vector2 vector2_add(Vector2 add1, Vector2 add2);
Vector2 vector2_sub(Vector2 sub1, Vector2 sub2);
Color color(int r, int g, int b, int a);

#endif // _GRAVITY_GAUNTLET_TYPES_
