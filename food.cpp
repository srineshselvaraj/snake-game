#include <iostream>
#include <SDL2/SDL.h>
#include <random>
#include "food.h"

Food::Food(){
    x = 300;
    y = 200;
}

int Food::getX(){
    return x;
}
int Food::getY(){
    return y;
}

void Food::setRandomPosition(){
    //int randX = rand() % 40;
    //int randY = rand() % 40;
    std::uniform_int_distribution<int> positions(0, 39);
    std::random_device rd;
    std::mt19937 rng(rd());
    int randX = positions(rng);
    int randY = positions(rng);
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