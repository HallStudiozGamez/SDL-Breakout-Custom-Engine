#include <SDL3/SDL.h>
#include <stdio.h>
#include <createwindow.h>
#include "graphics.h"
#include "sprites.h"
#include "entity.h"
#include <math.h>
void renderPlayer(struct Game *game);
void renderBall(struct Game *game);
void renderBricks(struct Game *game);
double fps(int framePerSecond){
    return (1000/framePerSecond);
}
void renderGame(struct Game *game) {
    clearScreen(game, BLACK);
    SDL_RenderClear(game->gameRenderer);
    renderPlayer(game);
    renderBall(game);
    renderBricks(game);
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
void renderBricks(struct Game *game) {
    for (int i = 0; i < 64; i++){
        uint8_t *color;
        uint8_t *colors[] = {RED, RED, ORANGE, YELLOW, GREEN, GREEN, BLUE, BLUE};
        color = colors[i/8];
        drawRect(game, game->entities[i+2].x, game->entities[i+2].y, 28, 6, color);
    }
}
void renderBall(struct Game *game) {
    drawRect(game, game->entities[1].x, game->entities[1].y, 4, 4, WHITE);
}
void printPlayer(struct Game *game){
    printf("(%d, ",game->entities[0].x);
    printf("%d)\n",game->entities[0].y);
}
