#if !defined(_GRAVITY_GAUNTLET_RENDERER_)
#define _GRAVITY_GAUNTLET_RENDERER_
#include "types.h"
#include "shader.h"
#include "SDL2/SDL.h"

class Renderer{
    private:
        SDL_Window* window;
    public:
        Renderer();
        void init();
        void BeginDrawing();
        void RenderTriangle(Vector2 p1,Vector2 p2, Vector2 p3, Color color);
        void RenderQuad(Vector2 top_left, Vector2 bottom_right, Color color);
        // void RenderTexture(Vector2 pos, const char *path);
        void EndDrawing();
};

#endif // _GRAVITY_GAUNTLET_RENDERER_
