#include <SDL3/SDL.h>
#include <stdio.h>
#include <createwindow.h>
#include "graphics.h"
#include "sprites.h"
#include "entity.h"
void renderPlayer(struct Game *game);
double fps(int framePerSecond){
    return (1000/framePerSecond);
}
void renderGame(struct Game *game) {
    clearScreen(game, BLACK);
    SDL_RenderClear(game->gameRenderer);
    for (int i = 0; i < 180; i+=20){
        drawRect(game, 160-2,i,4,16, WHITE);
    }
    renderPlayer(game);
}
void renderPlayer(struct Game *game) {
    if (game->entities[0].state == IDLE){
        game->entities[0].sprite.startFrame = 1;
        game->entities[0].sprite.animLength = 3;
        game->entities[0].sprite.animSpeed = fps(10);
    }
    animateEntity(game, 0);
    printf("(%f, ",game->entities[0].x);
    printf("%f)\n",game->entities[0].y);
}
