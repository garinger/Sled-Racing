#ifndef OBSTACLE_MANAGER_H
#define OBSTACLE_MANAGER_H
#include "common.h"
#include "obstacle.h"

void init_obstacle_manager(void);
void move_obstacles(double delta_time);
void draw_obstacles(void);
void cleanup_obstacles(void);

#endif