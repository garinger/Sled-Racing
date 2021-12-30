#ifndef PLAYER_H
#define PLAYER_H
#include "common.h"

typedef struct Player
{
    SDL_Rect texture_rect;
    char* texture_path;
    SDL_Texture* texture;
} Player;

void init_player(void);
void draw_player(void);
void move_player(bool move_right);
void load_player_texture(void);

#endif