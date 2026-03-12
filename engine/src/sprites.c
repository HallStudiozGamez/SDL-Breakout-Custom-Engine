#include <SDL3/SDL.h>
#include <sprites.h>
#include <stdio.h>
#include <stdlib.h>
#include <createwindow.h>
#include <SDL3_image/SDL_image.h>

SDL_Texture* loadSprite(struct Game *game, const char *filePath) {
	SDL_Surface *surface = IMG_Load(filePath);
	if (!surface) {
		fprintf(stderr, "Error loading sprite: %s\n", SDL_GetError());
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(game->gameRenderer, surface);
	SDL_DestroySurface(surface);
	if (!texture) {
		fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());
	}
	SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
	return texture;
}
void destroySpriteTexture(struct Game *game, int index) {
	game->textures[index] = NULL;
}
void drawSpriteScale(struct Game *game, int index, float x, float y, float w, float h) {
	SDL_FRect destRect = {x, y, w, h};
	x = SDL_round(x);
	y = SDL_round(y);
	SDL_Texture *texture = game->textures[index];
	if (!texture) {
		fprintf(stderr, "Error: Texture at index %d is NULL\n", index);
		return;
	}
	SDL_RenderTexture(game->gameRenderer, texture, NULL, &destRect);
}
void drawSprite(struct Game *game, int index, float x, float y) {
	float w, h;
	SDL_GetTextureSize(game->textures[index], &w, &h);
	x = SDL_round(x);
	y = SDL_round(y);
	SDL_FRect destRect = {x, y, w, h};
	SDL_Texture *texture = game->textures[index];
	if (!texture) {
		fprintf(stderr, "Error: Texture at index %d is NULL\n", index);
		return;
	}
	SDL_RenderTexture(game->gameRenderer, texture, NULL, &destRect);
}
void drawFrameScale(struct Game *game, int index, float x, float y, float w, float h, float xFrame, float yFrame, float wFrame, float hFrame) {
	SDL_FRect destRect = {x, y, w, h};
	x = SDL_round(x);
	y = SDL_round(y);
	SDL_FRect srcRect = {xFrame, yFrame, wFrame, hFrame};
	SDL_RenderTexture(game->gameRenderer, game->textures[index], &srcRect, &destRect);
}
void drawFrame(struct Game *game, int index, float x, float y, float width, int frame) {
	float w, h;
	x = SDL_round(x);
	y = SDL_round(y);
	SDL_GetTextureSize(game->textures[index], &w, &h);
	SDL_FRect destRect = {x, y, width, h};
	SDL_Texture *texture = game->textures[index];
	SDL_FRect srcRect = {frame*width, 0.0f, width, h};
	if (!texture) {
		fprintf(stderr, "Error: Texture at index %d is NULL\n", index);
		return;
	}
	SDL_RenderTexture(game->gameRenderer, texture, &srcRect, &destRect);
}
void closeSpriteTextures(struct Game *game) {
	for (int i = 0; i < 64; i++) {
		destroySpriteTexture(game, i);
	}
}