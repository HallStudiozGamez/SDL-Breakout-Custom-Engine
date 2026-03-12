#ifndef ENTITY_H
#define ENTITY_H
typedef enum {
	IDLE,
	WALK
} State;
struct animatedSprite {
	int sprite;
	int animSpeed;
	int frame;
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
void updateEntity(struct Entity *entity);
#endif