#include "obstacle.h"

void init_obstacle(Obstacle* ob, OBSTACLE_TYPE type)
{
    switch (type)
    {
        case LOG:
            ob->ob_type = LOG;
            ob->texture_rect.x = SCREEN_WIDTH;
            ob->texture_rect.y = SCREEN_HEIGHT;
            ob->texture_rect.w = 64;
            ob->texture_rect.h = 64;
            ob->texture_path = "C:/c/fun/Sled-Racing/res/penguin.png";
            ob->is_enabled = true;
            load_obstacle_texture(ob);
            printf("Log created!\n");
            break;

        case RAMP:
            ob->texture_path = "C:/c/fun/Sled-Racing/res/penguin.png";
            printf("Ramp created!\n");
            break;

        case ICE:
            ob->texture_path = "C:/c/fun/Sled-Racing/res/penguin.png";
            printf("Ice created!\n");
            break;

        case MOGULS:
            ob->texture_path = "C:/c/fun/Sled-Racing/res/penguin.png";
            printf("Moguls created!\n");
            break;

        case STUMP:
            ob->texture_path = "C:/c/fun/Sled-Racing/res/penguin.png";
            printf("Stump created!\n");
            break;
    }
}

void draw_obstacle(Obstacle* ob)
{
    SDL_RenderCopyF(renderer, ob->texture, NULL, &ob->texture_rect);
}

void move_obstacle(Obstacle* ob, double delta_time)
{
    ob->texture_rect.x -= 340 * delta_time;
    ob->texture_rect.y -= 200 * delta_time;
}

void load_obstacle_texture(Obstacle* ob)
{
    SDL_Surface* temp_surface = IMG_Load(ob->texture_path);
    if (temp_surface == NULL) 
    {
        printf("%s\n",IMG_GetError());
        exit(1);
    }
    else 
    {
        ob->texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
        if (ob->texture == NULL) 
        {
            printf("Couldn't obstacle texture from %s!\n%s\n", ob->texture_path, SDL_GetError());
        }
        
        SDL_FreeSurface(temp_surface);
        temp_surface = NULL;
    }
}