#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "common.h"

typedef enum
{
    LOG, RAMP, ICE, MOGULS, STUMP
} obstacle_type;

typedef struct Obstacle
{
    obstacle_type ob_type;
    SDL_Rect texture_rect;
    char* texture_path;
    SDL_Texture* texture;
} Obstacle;

void init_obstacle(Obstacle* ob, obstacle_type type);
void draw_obstacle(Obstacle* ob);
void move_obstacle(Obstacle* ob, double delta_time);
void load_obstacle_texture(Obstacle* ob);

#endif