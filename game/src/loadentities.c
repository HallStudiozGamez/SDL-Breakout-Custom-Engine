#include <loadentities.h>
#include <entity.h>
void loadEntites(struct Game *game){
	struct Entity *entities = game->entities;
	struct Entity player;
	struct animatedSprite playerAnim;
	initAnim(&playerAnim,1,16);
	initEntity(&player,30,30,5);
	player.sprite = playerAnim;
	entities[0] = player;
}