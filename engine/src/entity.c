#include <entity.h>
#include <createwindow.h>
#include <SDL3/SDL.h>
#include <sprites.h>
void updateEntity(struct Game *game, int index){
	game->entities[index].x += game->entities[index].dx;
	game->entities[index].y += game->entities[index].dy;
}
void animateEntity(struct Game *game, int index){
    game->entities[index].sprite.frame = (SDL_GetTicks() / 100) % game->entities[index].sprite.animLength;

    drawFrame(game, game->entities[index].sprite.sprite, game->entities[index].x, game->entities[index].y, 16, 0);
}
void initEntity(struct Entity *entity, float x, float y, float speed){
	entity->x = x;
	entity->y = y;
	entity->dx = 0;
	entity->dy = 0;
	entity->speed = speed;
	entity->state = IDLE;
}
void initAnim(struct animatedSprite *anim, int sprite, int width){
	anim->sprite = sprite;
	anim->width = width;
	anim->frame = 0;
	anim->startFrame = 0;
	anim->animSpeed = 1;
	anim->animLength = 1;
}