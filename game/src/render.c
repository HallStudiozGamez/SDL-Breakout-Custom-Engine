#include <SDL3/SDL.h>
#include <stdio.h>
#include <createwindow.h>
#include "graphics.h"
#include "sprites.h"
#include "entity.h"
void renderPlayer(struct Game *game);
void renderGame(struct Game *game) {
    clearScreen(game, BLACK);
    SDL_RenderClear(game->gameRenderer);
    for (int i = 0; i < 180; i+=20){
        drawRect(game, 160-2,i,4,16, WHITE);
    }
    renderPlayer(game);
    animateEntity(game, 0);
}
void renderPlayer(struct Game *game) {
    drawRect(game, game->entities[0].x,game->entities[0].y,40,40,WHITE);
    printf("(%f, ",game->entities[0].x);
    printf("%f)\n",game->entities[0].y);
}
