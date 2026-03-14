#include <loadentities.h>
#include <entity.h>
#include <sprites.h>
void loadEntites(struct Game *game){
	struct Entity *entities = game->entities;
	struct Entity player;
	struct animatedSprite playerAnim;
	initAnim(&playerAnim,0,16);
	initEntity(&player,120,300,3);
	player.sprite = playerAnim;
	entities[0] = player;

	struct Entity ball;
	initEntity(&ball,120,200,3);
	ball.dx = ball.speed;
	ball.dy = -ball.speed;
	entities[1] = ball;
}
void loadGraphics(struct Game *game){
	const char *textures[] = {"assets/texture.png"};
    int size = sizeof(textures) / sizeof(textures[0]);
    for (int i = 0; i < size; i++){
        game->textures[i] = loadSprite(game,textures[i]);
    }
}