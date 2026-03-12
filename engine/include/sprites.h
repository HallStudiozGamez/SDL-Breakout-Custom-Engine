#ifndef SPRITES_H
#define SPRITES_H
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <createwindow.h>

SDL_Texture* loadSprite(struct Game *game, const char *filePath);
void drawSpriteScale(struct Game *game, int index, float x, float y, float w, float h);
void drawSprite(struct Game *game, int index, float x, float y);
void drawFrameScale(struct Game *game, int index, float x, float y, float w, float h, float xFrame, float yFrame, float wFrame, float hFrame);
void drawFrame(struct Game *game, int index, float x, float y, float width, int frame);
void destroySpriteTexture(struct Game *game, int index);
void closeSpriteTextures(struct Game *game);
#endif