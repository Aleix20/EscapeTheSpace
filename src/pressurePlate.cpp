#include "pressurePlate.h"
#include "world.h"
#include "game.h"
PressurePlate::PressurePlate()
{
}
PressurePlate::PressurePlate(Vector2 position, Vector2 doorPosition, int numberOfPlates, eCellType cellToChange, eCellType collisionToChange, eDoorType doorDirection, sDoor* door)
{
	this->position = position;
	this->doorPosition = doorPosition;
	this->numberOfPlates = numberOfPlates;
	this->cellToChange = cellToChange;
	this->collisionToChange = collisionToChange;
	this->doorDirection = doorDirection;
	this->door = door;
	
}

void PressurePlate::checkDistance(World* world)
{
	Player* player1 = &world->players[0];
	Player* player2 = &world->players[1];
	
	//Pressure plate activated if distance < 6
	if (player1->pos.distance(position) <= 6.0f || player2->pos.distance(position) <= 6.0f) {

		if (!this->activacion) {
			Game::instance->synth.playSample("data/sounds/plate.wav", 0.6, false);
			this->activacion = true;
		}
		//Each plate will open a different door lock
		if (numberOfPlates == 1) {
			door->lock1 = false;
		}
		if (numberOfPlates == 2) {
			door->lock2 = false;
		}

		//if both locks opened, modify map and collisions
		if (door->lock1 == false && door->lock2 == false) {

			//play audio one time
			if (door->exists) {
				Game::instance->synth.playSample("data/sounds/door.wav", 1, false);
				door->exists = false;
			}

			/*Different types of doors == different cells to modify*/
			Vector2i cellCord = world->worldToCell(doorPosition, 8);
			if (doorDirection == eDoorType::VERTICAL) {
				world->mapaActual->setCell(cellCord.x, cellCord.y, eCellType::FLOORO);
				world->mapaActual->setCell(cellCord.x, cellCord.y+1, eCellType::FLOORO);
				world->mapaActualC->setCell(cellCord.x, cellCord.y, eCellType::FLOOR);
				world->mapaActualC->setCell(cellCord.x, cellCord.y+1, eCellType::FLOOR);
			}
			else if(doorDirection == eDoorType::HORITZONTAL3) {
				world->mapaActual->setCell(cellCord.x, cellCord.y, eCellType::FLOORO);
				world->mapaActual->setCell(cellCord.x+1, cellCord.y, eCellType::FLOORO);
				world->mapaActual->setCell(cellCord.x + 2, cellCord.y, eCellType::FLOORO);
				world->mapaActualC->setCell(cellCord.x, cellCord.y, eCellType::FLOOR);
				world->mapaActualC->setCell(cellCord.x+1, cellCord.y , eCellType::FLOOR);
				world->mapaActualC->setCell(cellCord.x + 2, cellCord.y, eCellType::FLOOR);
			}
			else if (doorDirection == eDoorType::HORITZONTAL2) {
				world->mapaActual->setCell(cellCord.x, cellCord.y, eCellType::FLOORO);
				world->mapaActual->setCell(cellCord.x + 1, cellCord.y, eCellType::FLOORO);
				world->mapaActualC->setCell(cellCord.x, cellCord.y, eCellType::FLOOR);
				world->mapaActualC->setCell(cellCord.x + 1, cellCord.y, eCellType::FLOOR);
				
			}
			else if (doorDirection == eDoorType::VERTICAL3) {
				world->mapaActual->setCell(cellCord.x, cellCord.y, eCellType::FLOORO);
				world->mapaActual->setCell(cellCord.x , cellCord.y+1, eCellType::FLOORO);
				world->mapaActual->setCell(cellCord.x , cellCord.y+2, eCellType::FLOORO);
				world->mapaActualC->setCell(cellCord.x, cellCord.y, eCellType::FLOOR);
				world->mapaActualC->setCell(cellCord.x , cellCord.y+1, eCellType::FLOOR);
				world->mapaActualC->setCell(cellCord.x , cellCord.y+2, eCellType::FLOOR);
			}
			else {
				world->mapaActual->setCell(cellCord.x, cellCord.y, eCellType::FLOORO);
				world->mapaActualC->setCell(cellCord.x, cellCord.y, eCellType::FLOOR);
			}
			
			
		}

	}
}
