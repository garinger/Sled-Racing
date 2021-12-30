#include "scene.h"

Scene main_scene;

void init_scene() 
{
    main_scene.texture_rect.x = 0;
    main_scene.texture_rect.y = 0;
    main_scene.texture_rect.w = SCREEN_WIDTH;
    main_scene.texture_rect.h = SCREEN_HEIGHT;
    main_scene.texture_path = "C:/c/fun/Sled-Racing/res/slope.png";
    load_scene_texture();
}

void draw_scene() 
{
    SDL_RenderCopy(renderer, main_scene.texture, NULL,  &main_scene.texture_rect);
}


void load_scene_texture()
{
    SDL_Surface* temp_surface = IMG_Load(main_scene.texture_path);
    if (temp_surface == NULL)
    {
        printf("%s\n",IMG_GetError());
        exit(1);
    }
    else
    {
        main_scene.texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
        if (main_scene.texture == NULL)
        {
            printf("Couldn't create scene texture from %s!\n%s\n", main_scene.texture_path, SDL_GetError());
        }

        SDL_FreeSurface(temp_surface);
        temp_surface = NULL;
    }
}