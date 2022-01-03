#include "obstacle_manager.h"

Obstacle* obstacles;
size_t array_size = 128;

void init_obstacle_manager()
{
    obstacles = calloc(array_size, sizeof(Obstacle));
    init_obstacle(&obstacles[0], LOG);
    init_obstacle(&obstacles[1], LOG);
    init_obstacle(&obstacles[2], LOG);

    obstacles[1].texture_rect.x += 50;
    obstacles[1].texture_rect.y += 50;

    obstacles[2].texture_rect.x += 100;
    obstacles[2].texture_rect.y += 100;
}

void move_obstacles(double delta_time)
{
    for (int i = 0; i < 50; i++)
    {
        if (obstacles[i].texture_path != NULL)
        {
            move_obstacle(&obstacles[i], delta_time);
            SDL_Delay(5);
        }
    }
}

void draw_obstacles()
{
    for (int i = 0; i < 50; i++)
    {
        if (obstacles[i].texture_path != NULL)
        {
            draw_obstacle(&obstacles[i]);
        }
    }
}