#include "game.h"
#include "window.h"
#include "events.h"
#include "player.h"
#include "scene.h"
#include "obstacle_manager.h"

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

void game_loop()
{
    Uint64 start_of_program = SDL_GetTicks();

    /* Delta Time */
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta_time = 0; // Time between each frame in seconds
    long frame_count = 0;

    /* Main game loop */
    while (!game_over)
    {
        last = now;
        now = SDL_GetPerformanceCounter();
        delta_time = ((now - last) * 1000 / (double)SDL_GetPerformanceFrequency()) * 0.001;

        on_input();
        on_update(delta_time);
        on_render();

        frame_count++;
        // printf("FPS: %f\n", 1 / delta_time);
    }
}

void on_input()
{
    process_events();
}

void on_update(double delta_time)
{
    check_for_new_obstacle();
    move_obstacles(delta_time);
}

void on_render()
{
    clear_window(); // Clear previous frame

    draw_scene(); // Update entities in frame
    draw_obstacles();
    draw_player();

    present_window(); // Draw new frame
}

void cleanup_game()
{
    printf("Cleaning up...\n");
    cleanup_window();
    cleanup_obstacles();
    printf("Exiting!\n");
}