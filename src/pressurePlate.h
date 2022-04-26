#include "framework.h"
#include "utils.h"

#ifndef PRESSUREPLATE_H
#define PRESSUREPLATE_H
class World;
class PressurePlate
{
public:
	Vector2 position;
	Vector2 doorPosition;
	int numberOfPlates;
	eCellType cellToChange;
	eCellType collisionToChange;
	eDoorType doorDirection;
	World* world;
	sDoor* door;
	bool activacion = false;
	PressurePlate();
	PressurePlate(Vector2 position, Vector2 doorPosition, int numberOfPlates, eCellType cellToChange, eCellType collisionToChange, eDoorType doorDirection,  sDoor* door);
	void checkDistance(World* world);
};
#endif

