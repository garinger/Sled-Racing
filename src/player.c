#include "player.h"

Player player;

void init_player()
{
    player.texture_rect.x = SCREEN_WIDTH / 3;
    player.texture_rect.y = SCREEN_HEIGHT / 3;
    player.texture_rect.w = 64;
    player.texture_rect.h = 64;
    player.texture_path = "C:/c/fun/Sled-Racing/res/penguin.png";
    load_player_texture();
}

void draw_player()
{
    SDL_RenderCopy(renderer, player.texture, NULL, &player.texture_rect);
}

void move_player(bool move_right)
{
    if (move_right)
    {
        player.texture_rect.x += 35.0;
        player.texture_rect.y -= 35.0;
    }
    else
    {
        player.texture_rect.x -= 35.0;
        player.texture_rect.y += 35.0;
    }
}

void load_player_texture()
{
    SDL_Surface* temp_surface = IMG_Load(player.texture_path);
    if (temp_surface == NULL) 
    {
        printf("%s\n",IMG_GetError());
        exit(1);
    }
    else 
    {
        player.texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
        if (player.texture == NULL) 
        {
            printf("Couldn't create player texture from %s!\n%s\n", player.texture_path, SDL_GetError());
        }

        SDL_FreeSurface(temp_surface);
        temp_surface = NULL;
    }
}