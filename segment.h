#include <stdio.h>
#include <SDL2/SDL.h>

class Segment{
    private:
        int x, y;
    public:
        Segment();
        Segment(int xPos, int yPos);
        int getX();
        int getY();
        void setPosition(int xPos, int yPos);
};