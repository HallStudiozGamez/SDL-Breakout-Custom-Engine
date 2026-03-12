#include <entity.h>

void updateEntity(struct Entity *entity){
	entity->x += entity->dx;
	entity->dy += entity->dy;

}