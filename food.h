#include <stdio.h>
#include <SDL2/SDL.h>

class Food{
    private:
        int x, y;
    public:
        Food();
        void spawn(SDL_Renderer* renderer, int width, int height);
        void setRandomPosition();
};