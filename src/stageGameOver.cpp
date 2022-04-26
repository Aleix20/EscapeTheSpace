#include "stageGameOver.h"
#include "game.h"
StageGameOver::StageGameOver()
{
}
void StageGameOver::render(Image* framebuffer, World* world, float* time)
{
	framebuffer->drawImage(world->gameOver, 0, 0);
}

void StageGameOver::update(double seconds_elapsed, World* world)
{
	if (Input::wasKeyPressed(SDL_SCANCODE_A)) {
		
		world->currentSound->stop();
		Game::instance->currentStage = eStages::STAGEMENU;
		Game::instance->resetWorld = true;
	}
}