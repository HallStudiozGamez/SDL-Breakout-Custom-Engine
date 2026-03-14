#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "createwindow.h"
#include "inputs.h"
#include "render.h"
#include "loadentities.h"
#include "sprites.h"
#define GAME_INTERNAL_WIDTH 320
#define GAME_INTERNAL_HEIGHT 180
#define SDL_FLAGS (SDL_INIT_VIDEO | SDL_INIT_EVENTS)
#define WINDOW_TITLE "Game"
bool createGameWindow(struct Game *game, int width, int height);
void closeGameWindow(struct Game *game);
void gameRun(struct Game *game);

bool createGameWindow(struct Game *game, int width, int height) {
    if (SDL_Init(SDL_FLAGS) < 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return false;
    }
    game->gameWindow = SDL_CreateWindow(WINDOW_TITLE, width, height, 0);
    if (!game->gameWindow) {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return false;
    }

    game->gameRenderer = SDL_CreateRenderer(game->gameWindow, NULL);
    if (!game->gameRenderer) {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(game->gameWindow);
        game->gameWindow = NULL;
        return false;
    }
    SDL_SetRenderLogicalPresentation(game->gameRenderer, GAME_INTERNAL_WIDTH, GAME_INTERNAL_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    const char *textures[] = {"assets/texture.png","assets/image.png"};
    int size = sizeof(textures) / sizeof(textures[0]);
    for (int i = 0; i < size; i++){
        game->textures[i] = loadSprite(game,textures[i]);
    }
    TTF_Init();
    game->font = TTF_OpenFont("assets/Jersey10-Regular.ttf", 18);
    loadEntites(game);
    return true;
}
void closeGameWindow(struct Game *game) {
    if (game->gameWindow) {
        SDL_DestroyWindow(game->gameWindow);
        game->gameWindow = NULL;
    }
    if (game->gameRenderer) {
        SDL_DestroyRenderer(game->gameRenderer);
        game->gameRenderer = NULL;
    }
    closeSpriteTextures(game);
    TTF_CloseFont(game->font);
    TTF_Quit();
    SDL_Quit();
}
void updateEnemy(struct Game *game){
    /*if(ball->cy - 8> game->enemy.y){
        game->enemy.y += 3;
    } else if(ball->cy + 8 < game->enemy.y){
        game->enemy.y += -3;
    }
    if (game->points[0] == 10 || game->points[1]==10){
        game->points[0] = 0;
        game->points[1] = 0;
    }*/
}
void gameRun(struct Game *game) {
    handleInput(game);
    playerInput(game);
    SDL_RenderClear(game->gameRenderer);
    renderGame(game);
    SDL_RenderPresent(game->gameRenderer);
    SDL_Delay(16);
}