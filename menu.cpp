#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "menu.h"
#include <string>

Menu::Menu(){
    score = 0;
}

SDL_Texture* Menu::initializeScoreText(SDL_Renderer* renderer){
    TTF_Font* roboto = TTF_OpenFont("roboto.ttf", 64);
    std::string scoreText = std::to_string(score);
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(roboto, scoreText.c_str(), {255, 255, 255});
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_QueryTexture(scoreTexture, NULL, NULL, NULL, NULL);
    SDL_FreeSurface(scoreSurface);
    return scoreTexture;
}

void Menu::updateScoreText(SDL_Renderer* renderer, SDL_Texture* texture){
    SDL_Rect rect = {0, 0, 30, 50};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
}

void Menu::destroyText(SDL_Texture* texture){
    SDL_DestroyTexture(texture);
}

void Menu::addScore(){
    score++;
}
/*
bool Menu::startGame(SDL_Event &e){
    if(e.type = SDL_KEYDOWN && e.key.repeat == 0){
        if(e.key.keysym.sym == SDLK_RETURN){
            return true;
        }
    }
    return false;
}

SDL_Texture* Menu::startMenu(SDL_Renderer* renderer, std::string text, SDL_Rect rect){
    TTF_Font* roboto = TTF_OpenFont("roboto.ttf", 64);
    SDL_Surface* menuSurface = TTF_RenderText_Solid(roboto, text.c_str(), {255, 255, 255});
    SDL_Texture* menuTexture = SDL_CreateTextureFromSurface(renderer, menuSurface);
    SDL_QueryTexture(menuTexture, NULL, NULL, NULL, NULL);
    SDL_RenderCopy(renderer, menuTexture, NULL, &rect);
    SDL_RenderPresent(renderer);
    SDL_FreeSurface(menuSurface);
    return menuTexture;
}
*/

