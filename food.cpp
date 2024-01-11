#include <iostream>
#include <SDL2/SDL.h>
#include "food.h"

Food::Food(){
    x = 300;
    y = 200;
}

void Food::setRandomPosition(){
    int randX = rand() % 40;
    int randY = rand() % 40;
    if(randX % 2 == 1){
        x = (randX - 1) * 10;
    }
    else{
        x = randX * 10;
    }
    if(randY % 2 == 1){
        y = (randY - 1) * 10;
    }
    else{
        y = randY * 10;
    }
}

void Food::spawn(SDL_Renderer* renderer, int width, int height){
    //setRandomPosition();
    SDL_Rect food = {x, y, width / 20, height / 20};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &food);
    SDL_RenderPresent(renderer);
}