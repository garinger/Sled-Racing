#ifndef PLAYER_H
#define PLAYER_H
#include "common.h"

typedef enum
{
    LEFT, RIGHT
} MOVE_DIR;


typedef struct Player
{
    SDL_FRect texture_rect;
    char* texture_path;
    SDL_Texture* texture;
} Player;

void init_player(void);
void draw_player(void);
void move_player(MOVE_DIR DIR);
void load_player_texture(void);

#endif