#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "snake.h"
#include "food.h"

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
            Food food;

            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(renderer);
            snake.spawn(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
            food.spawn(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

            if( TTF_Init() == -1 )
            {
                printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            }

            TTF_Font* Sans = TTF_OpenFont("roboto.ttf", 64);
            SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "0", {255, 255, 255});
            SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
            SDL_QueryTexture(message, NULL, NULL, NULL, NULL);
            SDL_Rect messageRect = {0, 0, 30, 50};

            SDL_Event e;
            bool quit = false;
            bool gameOver = false;
            while(quit == false){
                //SDL_RenderCopy(renderer, message, NULL, &messageRect);
                //SDL_RenderPresent(renderer);
                while(SDL_PollEvent(&e)){
                    if(e.type == SDL_QUIT){
                        quit = true;
                    }

                    snake.handleEvent(e);
                }

                if(SDL_GetTicks() % 200 == 0){
                    snake.move(SCREEN_WIDTH, SCREEN_HEIGHT);
                    if(snake.hitSegments() || snake.hitWall(SCREEN_WIDTH, SCREEN_HEIGHT)){
                        gameOver = true;
                    }
                    if(!gameOver){
                        if(snake.hitFood(snake.getX(), snake.getY(), food.getX(), food.getY())){
                            food.setRandomPosition();
                            snake.addLength();
                        }
                        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                        SDL_RenderClear(renderer);

                        snake.spawn(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                        food.spawn(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
                    }
                }
            }
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(message);
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}