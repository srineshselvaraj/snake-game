#include <stdio.h>
#include <SDL2/SDL.h>
#include "segment.h"
#include <vector>

class Snake{
    private:
        int length;
        int vX, vY, x, y;
        std::vector<Segment> segments;
    public:
        static const int UNIT_LENGTH = 20;
        static const int VELOCITY = 20;
        Snake();
        int getX();
        int getY();
        void spawn(SDL_Renderer* renderer, int width, int height);
        Segment* makeSegments(int len);
        void handleEvent(SDL_Event &e);
        void move(int width, int height);
        bool hitFood(int x1, int y1, int x2, int y2);
        bool hitSegments();
        bool hitWall();
        void render();
        void addLength();
};