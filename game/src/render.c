#include <SDL3/SDL.h>
#include <stdio.h>
#include <createwindow.h>
#include "graphics.h"
#include "sprites.h"
void renderGame(struct Game *game) {
    clearScreen(game, BLACK);
    SDL_RenderClear(game->gameRenderer);
    for (int i = 0; i < 180; i+=20){
        drawRect(game, 160-2,i,4,16, WHITE);
    }
}
void renderPlayer(struct Game *game) {
    /*player->startFrame = 1;
    player->animLength = 3;
    player->frame = (SDL_GetTicks() / 100) % player->animLength;
    switch (player->state)
    {
    case WALK:
        drawFrame(game, 1,player->x, player->y, 16, (player->frame)+player->startFrame);
        break;
    case IDLE:
        drawFrame(game, 1, player->x, player->y, 16, 0);
        break;
    default:
        break;
    }*/
}