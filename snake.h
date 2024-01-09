#include <stdio.h>
#include <SDL2/SDL.h>

class Snake{
    private:
        int length, vX, vY, x, y;    
    public:
        static const int UNIT_LENGTH = 20;
        static const int VELOCITY = 20;
        Snake();
        void spawn(SDL_Renderer* renderer, int width, int height);
        void handleEvent(SDL_Event &e);
        void move(int width, int height);
        void render();
        void addLength();
};