#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "createwindow.h"

int main(int argc, char *argv[]) {
    bool exitStatus = EXIT_FAILURE;
    struct Game game = {0};
    if (!createGameWindow(&game, 854, 480)) {
        return exitStatus;
    } else {
        exitStatus = EXIT_SUCCESS;
    }
    game.running = 1;
    while (game.running > 0) {
        gameRun(&game);
    }

    closeGameWindow(&game);
    
    return exitStatus;
}