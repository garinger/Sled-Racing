#ifndef WINDOW_H
#define WINDOW_H
#include "common.h"

SDL_Window* window;
SDL_Renderer* renderer;
bool init_window(void);
void clear_window(void);
void present_window(void);
void cleanup_window(void);

#endif