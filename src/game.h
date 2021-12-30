#ifndef GAME_H
#define GAME_H
#include "common.h"

bool init_game(void);
void game_loop(void);
void on_input(void);
void on_update(double delta_time);
void on_render(void);
void cleanup_game(void);

#endif