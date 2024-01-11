#include <SDL2/SDL.h>
#include <stdio.h>
#include "snake.h"

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* args[]){
    SDL_Window* window = NULL;
    //SDL_Surface* screenSurface = NULL;
    SDL_Renderer* renderer = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else{
        window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL){
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else{
            /*screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
            SDL_UpdateWindowSurface(window);*/

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            Snake snake;

            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(renderer);
            snake.spawn(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

            SDL_Event e;
            bool quit = false;
            while(quit == false){
                while(SDL_PollEvent(&e)){
                    if(e.type == SDL_QUIT){
                        quit = true;
                    }

                    snake.handleEvent(e);
                }

                snake.move(SCREEN_WIDTH, SCREEN_HEIGHT);
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                SDL_RenderClear(renderer);

                snake.spawn(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}