#ifndef ENTITY_H
#define ENTITY_H

struct Game;
typedef enum {
	IDLE,
	WALK
} State;
struct animatedSprite {
	int sprite;
	int animSpeed;
	int frame;
	int width;
	int startFrame;
	int animLength;
};
struct Entity {
	float x;
	float y;
	float dx;
	float dy;
	float speed;
	struct animatedSprite sprite;
	State state;
};
void initEntity(struct Entity *entity, float x, float y, float speed);
void initAnim(struct animatedSprite *anim, int sprite, int width);
void updateEntity(struct Game *game, int index);
void animateEntity(struct Game *game, int index);
#endif