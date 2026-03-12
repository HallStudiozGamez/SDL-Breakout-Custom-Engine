#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <stdint.h>

#define PINK (uint8_t[4]){255, 150, 192, 255}
#define RED (uint8_t[4]){255, 0, 0, 255}
#define DARKRED (uint8_t[4]){128, 0, 0, 255}
#define GREEN (uint8_t[4]){0, 255, 0, 255}
#define DARKGREEN (uint8_t[4]){0, 128, 0, 255}
#define BLUE (uint8_t[4]){0, 0, 255, 255}
#define DARKBLUE (uint8_t[4]){0, 0, 128, 255}
#define YELLOW (uint8_t[4]){255, 255, 0, 255}
#define DARKYELLOW (uint8_t[4]){128, 128, 0, 255}
#define PURPLE (uint8_t[4]){255, 0, 255, 255}
#define DARKPURPLE (uint8_t[4]){128, 0, 128, 255}
#define CYAN (uint8_t[4]){0, 255, 255, 255}
#define DARKCYAN (uint8_t[4]){0, 128, 128, 255}
#define WHITE (uint8_t[4]){255, 255, 255, 255}
#define LIGHTGRAY (uint8_t[4]){192, 192, 192, 255}
#define GRAY (uint8_t[4]){128, 128, 128, 255}
#define DARKGRAY (uint8_t[4]){64, 64, 64, 255}
#define BLACK (uint8_t[4]){0, 0, 0, 255}
#define ORANGE (uint8_t[4]){255, 128, 0, 255}
#define DARKORANGE (uint8_t[4]){128, 64, 0, 255}
void drawRect(struct Game *game, float x, float y, float w, float h, uint8_t color[4]);
void clearScreen(struct Game *game, uint8_t color[4]);
void drawPixel(struct Game *game, float x, float y, uint8_t color[4]);
void drawCircle(struct Game *game, float x, float y, float radius, uint8_t color[4]);
void drawLabel(struct Game *game, const char *text, float x, float y, uint8_t color[4]);
void drawLabelInt(struct Game *game, int text,float x, float y, uint8_t color[4]);
#endif