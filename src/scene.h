#ifndef SCENE_H
#define SCENE_H
#include "common.h"

typedef struct Scene {
    SDL_Rect texture_rect;
    char* texture_path;
    SDL_Texture* texture;
} Scene;

void init_scene(void);
void draw_scene(void);
void load_scene_texture(void);

#endif