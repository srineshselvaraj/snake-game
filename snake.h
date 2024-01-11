#include <stdio.h>
#include <SDL2/SDL.h>
#include "segment.h"
#include <vector>

class Snake{
    private:
        int length;
        float vX, vY, x, y;
        std::vector<Segment> segments;
    public:
        static const int UNIT_LENGTH = 20;
        static constexpr float VELOCITY = 0.05;
        Snake();
        void spawn(SDL_Renderer* renderer, int width, int height);
        Segment* makeSegments(int len);
        void handleEvent(SDL_Event &e);
        void move(int width, int height);
        void render();
        void addLength();
};