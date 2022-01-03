#include "window.h"

bool init_window() 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        printf("Couldn't initalize SDL! %s\n", SDL_GetError());
        return false;
    }

    int img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(IMG_INIT_PNG) & img_flags)) 
    {
        printf("Couldn't initalize SDL_Image! %s\n", IMG_GetError());
        return false;
    }

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    printf("Window initialized!\n");
    return true;
}

void clear_window()
{
    SDL_SetRenderDrawColor(renderer, 0, 130, 200, 255);
    SDL_RenderClear(renderer);
}

void present_window()
{
    SDL_RenderPresent(renderer);
}

void cleanup_window()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;
}