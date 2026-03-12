#include <SDL3/SDL.h>
#include <stdio.h>
#include <createwindow.h>
#include <string.h>
#include <math.h>
#include "graphics.h"
void drawRect(struct Game *game, float x, float y, float w, float h, uint8_t color[4]);
void clearScreen(struct Game *game, uint8_t color[4]);
void drawPixel(struct Game *game, float x, float y, uint8_t color[4]);
void drawCircle(struct Game *game, float x, float y, float radius, uint8_t color[4]);
void drawLabel(struct Game *game, const char *text,float x, float y, uint8_t color[4]);
void clearScreen(struct Game *game, uint8_t color[4]) {
	SDL_SetRenderDrawColor(game->gameRenderer, color[0], color[1], color[2], color[3]);
	SDL_RenderClear(game->gameRenderer);
}
void drawRect(struct Game *game, float x, float y, float w, float h, uint8_t color[4]) {
	x = SDL_round(x);
	y = SDL_round(y);
	SDL_FRect rect = {x, y, w, h};
	SDL_SetRenderDrawColor(game->gameRenderer, color[0], color[1], color[2], color[3]);
	SDL_RenderFillRect(game->gameRenderer,&rect);
}
void drawPixel(struct Game *game, float x, float y, uint8_t color[4]) {
	SDL_SetRenderDrawColor(game->gameRenderer, color[0], color[1], color[2], color[3]);
	SDL_RenderPoint(game->gameRenderer, x, y);
}
void drawLabel(struct Game *game, const char *text,float x, float y, uint8_t color[4]) {
	SDL_Color c = {color[0],color[1], color[2]};
	size_t length = strlen(text);
	SDL_Surface *textSuface = TTF_RenderText_Solid(game->font, text,length, c);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(game->gameRenderer, textSuface);
	SDL_DestroySurface(textSuface);
	float w, h = SDL_GetTextureSize(texture,&w, &h);
	SDL_FRect destRect = {x, y, w, 18};
	SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
	SDL_RenderTexture(game->gameRenderer,texture,NULL,&destRect);

}
void drawLabelInt(struct Game *game, int text,float x, float y, uint8_t color[4]){
	int length = floor(log10(text)) + 1;
	char buffer[length];
    snprintf(buffer, sizeof(buffer), "%d", text);
    drawLabel(game, buffer, 90,30,WHITE);
}
void drawCircle(struct Game *game, float x, float y, float radius, uint8_t color[4]) {
	SDL_SetRenderDrawColor(game->gameRenderer, color[0], color[1], color[2], color[3]);
	for (int w = 0; w < radius * 2; w++) {
		for (int h = 0; h < radius * 2; h++) {
			int dx = radius - w; // horizontal offset
			int dy = radius - h; // vertical offset
			if ((dx*dx + dy*dy) <= (radius * radius)) {
				SDL_RenderPoint(game->gameRenderer, x + dx, y + dy);
			}
		}
	}
}