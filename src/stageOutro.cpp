#include "stageOutro.h"

#include "game.h"

StageOutro::StageOutro()
{
}

void StageOutro::render(Image* framebuffer, World* world, float* time)
{
	framebuffer->drawImage(world->outro, 0, 0);
}

void StageOutro::update(double seconds_elapsed, World* world)
{
	if (Input::wasKeyPressed(SDL_SCANCODE_A)) {
		world->currentSound->stop();
		Game::instance->currentStage = eStages::STAGEMENU;
		Game::instance->resetWorld = true;

	}
}
