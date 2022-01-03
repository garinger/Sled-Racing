#include "game.h"
#include "window.h"
#include "events.h"
#include "player.h"
#include "scene.h"
#include "obstacle_manager.h"

void game_loop()
{
    /* Delta Time */
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta_time = 0;

    /* Main game loop */
    while (!game_over)
    {
        last = now;
        now = SDL_GetPerformanceCounter();
        delta_time = ((now - last) * 1000 / (double)SDL_GetPerformanceFrequency()) * 0.001;

        on_input();
        on_update(delta_time);
        on_render();
    }
}

bool init_game()
{
    game_over = false;

    if (!init_window() && !init_events())
    {
        return false;
    }

    // Setup player & scene
    init_player();
    init_scene();
    init_obstacle_manager();

    return true;
}

void on_input()
{
    process_events();
}

void on_update(double delta_time)
{
    move_obstacles(delta_time);
}

void on_render()
{
    clear_window(); // Clear previous frame

    draw_scene(); // Update entities in frame
    draw_player();
    draw_obstacles();

    present_window(); // Draw new frame
}

void cleanup_game()
{
    printf("Cleaning up...\n");
    cleanup_window();
    cleanup_obstacles();
    printf("Exiting!\n");
}