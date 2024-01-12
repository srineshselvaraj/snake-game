#include <iostream>
#include <SDL2/SDL.h>
#include "snake.h"

Snake::Snake(){
    length = 3;
    vX = 0;
    vY = 0;
    x = 100;
    y = 200;
    segments.push_back(Segment(x-20, y));
    segments.push_back(Segment(x-40, y));
}

int Snake::getX(){
    return x;
}

int Snake::getY(){
    return y;
}

void Snake::spawn(SDL_Renderer* renderer, int width, int height){
    SDL_Rect snake = {(int)x, (int)y, width / 20, height / 20};
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &snake);
    for(int i = 0; i < length - 1; i++){
        SDL_Rect seg = {segments[i].getX(), segments[i].getY(), width / 20, height / 20};
        SDL_RenderFillRect(renderer, &seg);
    }
    SDL_RenderPresent(renderer);
}
/*
Segment* Snake::makeSegments(int len){
    Segment segments[len - 1];
    for(int i = 0; i < len - 1; i++){
        segments[i] = Segment(x - (20*(i+1)), y);
    }
    return segments;
}
*/

void Snake::handleEvent(SDL_Event &e){
    if(e.type = SDL_KEYDOWN && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_UP:
                if(vY <= 0){
                    vY = 0;
                    vY -= VELOCITY;
                    vX = 0;
                }
                break;
            case SDLK_DOWN:
                if(vY >= 0){
                    vY = 0;
                    vY += VELOCITY;
                    vX = 0;
                }
                break;
            case SDLK_LEFT:
                if(vX <= 0){
                    vX = 0;
                    vX -= VELOCITY;
                    vY = 0;
                }
                break;
            case SDLK_RIGHT:
                if(vX >= 0){
                    vX = 0;
                    vX += VELOCITY;
                    vY = 0;
                }
                break;
        }
    }
}

void Snake::move(int width, int height){
    if(vX != 0 || vY != 0){
        for(int i = length - 1; i > 0; i--){
            //std::cout << segments[i].getX() << " ";
            segments[i].setPosition(segments[i-1].getX(), segments[i-1].getY());
        }
        segments[0].setPosition(x, y);
        //std::cout << "" << std::endl;
    }
    x += vX;
    if((x < 0) || (x + UNIT_LENGTH > width)){
        x -= vX;
    }

    y += vY;
    if((y < 0) || (y + UNIT_LENGTH > height)){
        y -= vY;
    }
}

bool Snake::hitFood(int x1, int y1, int x2, int y2){
    /*int leftA = x1;
    int rightA = x1 + (width / 20);
    int topA = y1;
    int bottomA = y1 + (height / 20);
    int leftB = x2;
    int rightB = x2 + (width / 20);
    int topB = y2;
    int bottomB = y2 + (height / 20);

    if(bottomA >= topB || topA <= bottomB || rightA <= leftB || leftA >= rightB){
        return false;
    }
    */
    if(x1 == x2 && y1 == y2){
        //std::cout << "collision" << std::endl;
        return true;
    }
    return false;
}
