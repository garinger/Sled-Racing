#include "common.h"
#include "game.h"

void init(void);
void cleanup(void);

int main(int argc, char* argv[])
{
    init_game();
    game_loop();

    cleanup_game();
    return 0;
}