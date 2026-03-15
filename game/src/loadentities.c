#include <loadentities.h>
#include <entity.h>
#include <math.h>
#include <sprites.h>
void loadEntites(struct Game *game){
	game->points[0] = 0;
	struct Entity *entities = game->entities;
	struct Entity player;
	struct animatedSprite playerAnim;
	initAnim(&playerAnim,0,16);
	initEntity(&player,120,300,5);
	player.sprite = playerAnim;
	entities[0] = player;

	struct Entity ball;
	initEntity(&ball,120,200,2);
	ball.dy = -ball.speed;
	entities[1] = ball;
	
	for (int i = 0; i < 64; i++){
		struct Entity brick;
		initEntity(&brick, (i % 8)*30+2,floor(i / 8)*10+32, 0);
		brick.state = IDLE;
		entities[i+2] = brick;
	}
}
void loadGraphics(struct Game *game){
	const char *textures[] = {"assets/texture.png"};
    int size = sizeof(textures) / sizeof(textures[0]);
    for (int i = 0; i < size; i++){
        game->textures[i] = loadSprite(game,textures[i]);
    }
}