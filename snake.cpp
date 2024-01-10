#include <iostream>
#include <SDL2/SDL.h>
#include "snake.h"

Snake::Snake(){
    length = 1;
    vX = 0;
    vY = 0;
    x = 0;
    y = 0;
}

void Snake::spawn(SDL_Renderer* renderer, int width, int height){
    SDL_Rect snake = {(int)x, (int)y, width / 20, height / 20};
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &snake);
    SDL_RenderPresent(renderer);
}

void Snake::handleEvent(SDL_Event &e){
    if(e.type = SDL_KEYDOWN && e.key.repeat == 0){
        switch(e.key.keysym.sym){
            case SDLK_UP:
                vY = 0;
                vY -= VELOCITY;
                vX = 0;
                break;
            case SDLK_DOWN:
                vY = 0;
                vY += VELOCITY;
                vX = 0;
                break;
            case SDLK_LEFT:
                vX = 0;
                vX -= VELOCITY;
                vY = 0;
                break;
            case SDLK_RIGHT:
                vX = 0;
                vX += VELOCITY;
                vY = 0;
                break;
        }
    }
}

void Snake::move(int width, int height){
    x += vX;
    if((x < 0) || (x + UNIT_LENGTH > width)){
        x -= vX;
    }

    y += vY;
    if((y < 0) || (y + UNIT_LENGTH > height)){
        y -= vY;
    }
}
