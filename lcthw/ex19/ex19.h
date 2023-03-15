#ifndef _ex19_h
#define _ex19_h

#include "object.h"

struct Monster {
	Object proto;
	int hit_points;
} Monster;

// typedef struct Monster Monster;

int Monster_attack(void *self, int damage);
int Monster_init(void *self);

struct Room {
	Object proto;

	Monster *bad_guy;

	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
} Room;

// typedef struct Room Room;

void *Room_move(void *self, Direction
