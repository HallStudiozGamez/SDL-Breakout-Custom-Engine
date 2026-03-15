#include <update.h>
#include <createwindow.h>
#include <entity.h>
#include <stdio.h>
#include <math.h>
void updatePlayer(struct Game *game){
	struct Entity *player = &game->entities[0];
	if (player->x < 0){
		player->x = 0;
	}
	/*entity 0 is the player. it's defined in loadentities.c
	32 is the width of the paddle.
	240 is the width of the screen.
	*/
	if (player->x + 32 > 240){
		player->x = 240 - 32;
	}
	updateEntity(game, 0);
}
int findMax(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}
int findMin(int a, int b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}
void updateBricks(struct Game *game){
	struct Entity *ball = &game->entities[1];
	struct Entity *player = &game->entities[0];
	if (game->points[1] <= 0){
		for (int i = 0; i < 64; i++){
			game->entities[i+2].state = IDLE;
		}
		game->points[1] = 64;
		ball->x = 120;
		ball->y = 200;
		ball->dx = 0;
		ball->dy = -ball->speed;
		player->x = 120;
	}
}
void updateBall(struct Game *game){
	struct Entity *ball = &game->entities[1];
	struct Entity *player = &game->entities[0];
	int relvativeIntersect = ((player->x+16) - (ball->x+2));
	int brickIDX = (ball->x / 30);
	int brickIDY = ((ball->y-32) / 10);
	int index = (brickIDY * 8) + brickIDX + 2; //the 2 is because of the entity offset, 0 is the player, 1 is the ball.
	if (ball->x < 0){
		ball->x = 0;
		ball->dx *= -1;
	}
	if (ball->x + 4 > 240){
		ball->x = 240 - 4;
		ball->dx *= -1;
	}
	if (ball->y < 32){ //hud at 32px
		ball->y = 32;
		ball->dy *= -1;
	}
	if (-16 <= relvativeIntersect && relvativeIntersect <= 16){
		if (player->y <= ball->y+4 && ball->y+4 <= player->y+4){
			ball->y = player->y-4;
			ball->dy *= -1;
			int bounceAngle = relvativeIntersect * 60;
			ball->dx = ball->speed*-sin(bounceAngle)*2;
		}
	}
	if (ball->y > 320){
		ball->x = 120;
		ball->y = 200;
		ball->dx = 0;
		ball->dy = -ball->speed;
		player->x = 120;
	}
	if (index < 66){
		printf("%d\n",index);
	}
	
	for (int i = findMax(2, index-2);i<findMin(66,index+2);i++){
		SDL_Rect ballRect = {ball->x -2,ball->y -4,4,4};
		SDL_Rect brick = {game->entities[i].x,game->entities[i].y, 30, 10};
		if (SDL_HasRectIntersection(&ballRect, &brick)){
			if (game->entities[i].state == IDLE){
				ball->dx *= -1;
				ball->dy = 3;
				game->entities[i].state = DEAD;
				game->points[0] += (10 - brickIDY) * 10;
				game->points[1] -= 1;
			}
		}
	}
	updateBricks(game);
	updateEntity(game, 1);
}