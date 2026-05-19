#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H
#include <SDL3_ttf/SDL_ttf.h>
#include <entity.h>
struct Camera{
    int x;
    int y;
};
struct Game {
    SDL_Window *gameWindow;
    SDL_Renderer *gameRenderer;
    SDL_Event *event;
    SDL_Texture *textures[64];
    TTF_Font *font;
    struct Entity entities[128];
    struct Camera *camera;
    int points[2];
    int running;
};

struct Entity;
bool createGameWindow(struct Game *game, int width, int height);
void closeGameWindow(struct Game *game);
void gameRun(struct Game *game);

#endif 