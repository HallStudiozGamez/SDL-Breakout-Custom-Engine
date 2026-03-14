#include <update.h>
#include <createwindow.h>
#include <entity.h>
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
void updateBall(struct Game *game){
	struct Entity *ball = &game->entities[1];
	if (ball->x < 0){
		ball->x = 0;
		ball->dx *= -1;
	}
	if (ball->x + 4 > 240){
		ball->x = 240 - 4;
		ball->dx *= -1;
	}
	if (ball->y < 0){
		ball->y = 0;
		ball->dy *= -1;
	}
	updateEntity(game, 1);
}