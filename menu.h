#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Menu{
    private:
        int score;
    public:
        Menu();
        SDL_Texture* initializeScoreText(SDL_Renderer* renderer);
        void updateScoreText(SDL_Renderer* renderer, SDL_Texture* texture);
        void destroyText(SDL_Texture* texture);
        void addScore();
        bool startGame(SDL_Event &e);
        SDL_Texture* startMenu(SDL_Renderer* renderer, std::string text, SDL_Rect rect);
};