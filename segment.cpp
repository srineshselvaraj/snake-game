#include <iostream>
#include <SDL2/SDL.h>
#include "segment.h"

Segment::Segment(int xPos, int yPos){
    x = xPos;
    y = yPos;
}

int Segment::getX(){
    return x;
}

int Segment::getY(){
    return y;
}

void Segment::setPosition(int xPos, int yPos){
    x = xPos;
    y = yPos;
}