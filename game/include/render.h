#ifndef RENDER_H
#define RENDER_H
#include "sprites.h"
#include "createwindow.h"
struct Game;
void renderPlayer(struct Game *game);
void renderGame(struct Game *game);
void renderBall(struct Game *game);
#endif