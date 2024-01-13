#include <stdio.h>
#include <SDL2/SDL.h>

class Food{
    private:
        int x, y;
    public:
        Food();
        int getX();
        int getY();
        void spawn(SDL_Renderer* renderer, int width, int height);
        void setRandomPosition();
};