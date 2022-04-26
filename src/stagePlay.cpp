#include "stagePlay.h"
#include "game.h"

StagePlay::StagePlay()
{
}

void StagePlay::render(Image* framebuffer, World* world, float* time) 
{
	//map
	world->drawMap(framebuffer);

	//renfering players
	world->players[0].renderPlayer(framebuffer, *time);
	world->players[1].renderPlayer(framebuffer, *time);

	//HUD
	framebuffer->drawImage(world->gas, 3, 2, Area(0, 0, 8, 8));
	framebuffer->drawText(toString((float)world->numberOfGas), 11, 5, world->minifont, 4, 6);
	framebuffer->drawText(toString(world->time), framebuffer->width-20, 3, world->minifont, 4, 6);

	//Checking position for update map
	world->updateMap();

	//Game over
	if (world->time <= 0.0f) {
		Game::instance->currentStage = eStages::STAGEGAMEOVER;
	}

	
}

void StagePlay::update(double seconds_elapsed, World* world)
{
	//Timer for game over
	world->time -= seconds_elapsed;
	
	
	/*PLAYER 1 MOVEMENT*/
	Vector2 movement;
	Player& player = world->players[0];
		
	if (Input::isKeyPressed(SDL_SCANCODE_UP)) 
	{
		movement.y -= player.moveSpeed;

	}
	if (Input::isKeyPressed(SDL_SCANCODE_DOWN)) 
	{
		movement.y += player.moveSpeed;
	}


	if (Input::isKeyPressed(SDL_SCANCODE_LEFT)) 
	{
		movement.x -= player.moveSpeed;
	}
	if (Input::isKeyPressed(SDL_SCANCODE_RIGHT)) 
	{
		movement.x += player.moveSpeed;

	}
		
		
	Vector2 oldPlayerPos = player.pos;

	//update position with collision
	player.updatePos((movement * seconds_elapsed), world);

	//moving animation
	player.moving( oldPlayerPos);

	/*PLAYER 2 MOVEMENT*/
	Vector2 movement2;
	Player& player2 = world->players[1];

	if (Input::isKeyPressed(SDL_SCANCODE_W)) 
	{
		movement2.y -= player2.moveSpeed;
	}
	if (Input::isKeyPressed(SDL_SCANCODE_S))
	{
		movement2.y += player2.moveSpeed;
	}
	if (Input::isKeyPressed(SDL_SCANCODE_A)) 
	{
		movement2.x -= player2.moveSpeed;
	}
	if (Input::isKeyPressed(SDL_SCANCODE_D)) 
	{
		movement2.x += player2.moveSpeed;
	}

	Vector2 oldPlayerPos2 = player2.pos;
	//update position with collision
	player2.updatePos((movement2 * seconds_elapsed), world);

	//moving animation
	player2.moving(oldPlayerPos2);

	//Checking distance to pressure plates with the players
	int length = world->items[(int)world->mapaActualPos.x][(int)world->mapaActualPos.y].size;
	for (int i = 0; i < length;i++) {
		PressurePlate* plate = &world->items[(int) world->mapaActualPos.x][(int)world->mapaActualPos.y].plates[i];
		plate->checkDistance(world);
	}

	//Final stage, END GAME
	if (world->numberOfGas == 0 && world->mapaActualPos == Vector2(1,2) && world->sound) {
		Game::instance->synth.playSample("data/sounds/door.wav", 1, false);
		world->sound = false;
		Vector2i cellCord = world->worldToCell(Vector2(19*8,6*8), 8);
		world->mapaActual->setCell(cellCord.x, cellCord.y, eCellType::FLOORO);
		world->mapaActual->setCell(cellCord.x, cellCord.y + 1, eCellType::FLOORO);
		world->mapaActualC->setCell(cellCord.x, cellCord.y, eCellType::FLOOR);
		world->mapaActualC->setCell(cellCord.x, cellCord.y + 1, eCellType::FLOOR);
	}
		
	

}
