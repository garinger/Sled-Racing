#include "obstacle_manager.h"

struct ObstacleManager
{
    Obstacle* obstacles;
    size_t array_size;
    size_t curr_obstacle_count;
    Uint32 time_since_last_obstacle;
} manager;

void init_obstacle_manager()
{
    manager.array_size = 240;
    manager.curr_obstacle_count = 0;
    manager.time_since_last_obstacle = 0;
    manager.obstacles = calloc(manager.array_size, sizeof(Obstacle));
}

void init_new_obstacle()
{
    init_obstacle(&manager.obstacles[manager.curr_obstacle_count], LOG);
    manager.curr_obstacle_count++;
    manager.time_since_last_obstacle = SDL_GetTicks();
}

void check_for_new_obstacle()
{
    if (manager.curr_obstacle_count == 0)
    {
        init_new_obstacle();
    }
    else if (SDL_GetTicks() - manager.time_since_last_obstacle >= 2000)
    {
        init_new_obstacle();
    }
}

void move_obstacles(double delta_time)
{
    for (int i = 0; i < manager.curr_obstacle_count; i++)
    {
        if (manager.obstacles[i].is_enabled)
        {
            move_obstacle(&manager.obstacles[i], delta_time);
        }
    }
}

void draw_obstacles()
{
    for (int i = 0; i < manager.curr_obstacle_count; i++)
    {
        if (manager.obstacles[i].is_enabled && manager.obstacles[i].texture_rect.x < 1280 && manager.obstacles[i].texture_rect.y < 720)
        {
            draw_obstacle(&manager.obstacles[i]);
        }
    }
}

void cleanup_obstacles()
{
    printf("Destroying obstacles...\n");
    free(manager.obstacles);
}