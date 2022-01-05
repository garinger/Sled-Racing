#include "events.h"

bool init_events()
{
    printf("Events initialized!\n");
    return true;
}

void process_events()
{
    if (SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
            case SDL_QUIT:
                game_over = true;
                break;
            
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                    case SDLK_a:
                    case SDLK_LEFT:               
                        move_player(LEFT);
                        break;
                    
                    case SDLK_d:
                    case SDLK_RIGHT:
                        move_player(RIGHT);
                        break;
                }
        }
    }
}