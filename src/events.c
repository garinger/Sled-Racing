#include "events.h"

bool init_events()
{
    printf("Events initialized!\n");
    return true;
}

void process_events()
{
    if (SDL_WaitEvent(&e))
    {
        switch (e.type)
        {
            case SDL_QUIT:
                end_loop = true;
                break;
            
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                    /******************\
                    |  Player Movement |
                    \******************/
                    case SDLK_a:
                    case SDLK_LEFT:               
                        move_player(false);
                        break;
                    
                    case SDLK_d:
                    case SDLK_RIGHT:
                        move_player(true);
                        break;
                }
        }
    }
}