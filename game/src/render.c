#include <SDL3/SDL.h>
#include <stdio.h>
#include <createwindow.h>
#include "graphics.h"
#include "sprites.h"
#include "entity.h"
void renderPlayer(struct Game *game);
void renderBall(struct Game *game);
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
    renderBall(game);
}
void renderPlayer(struct Game *game) {
    //example animation code if needed
    /*if (game->entities[0].state == IDLE){
        game->entities[0].sprite.startFrame = 1;
        game->entities[0].sprite.animLength = 3;
        game->entities[0].sprite.animSpeed = fps(10);
    }*/
   drawRect(game, game->entities[0].x, game->entities[0].y, 32, 4, WHITE);
}
void renderBall(struct Game *game) {
    drawRect(game, game->entities[1].x, game->entities[1].y, 4, 4, WHITE);
}
void printPlayer(struct Game *game){
    printf("(%d, ",game->entities[0].x);
    printf("%d)\n",game->entities[0].y);
}
