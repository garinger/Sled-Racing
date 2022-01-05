#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "common.h"

typedef enum
{
    LOG, RAMP, ICE, MOGULS, STUMP
} OBSTACLE_TYPE;

typedef struct Obstacle
{
    bool is_enabled;
    OBSTACLE_TYPE ob_type;
    SDL_FRect texture_rect;
    char* texture_path;
    SDL_Texture* texture;
} Obstacle;

void init_obstacle(Obstacle* ob, OBSTACLE_TYPE type);
void draw_obstacle(Obstacle* ob);
void move_obstacle(Obstacle* ob, double delta_time);
void load_obstacle_texture(Obstacle* ob);

#endif