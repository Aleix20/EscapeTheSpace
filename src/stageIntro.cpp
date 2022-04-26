#include "stageIntro.h"
#include "game.h"


StageIntro::StageIntro()
{
}

void StageIntro::render(Image* framebuffer, World* world, float* time)
{
	framebuffer->drawImage(world->tutorial[world->tutorialPage],0,0);

}

void StageIntro::update(double seconds_elapsed, World* world)
{
	if (Input::wasKeyPressed(SDL_SCANCODE_RIGHT)) {
		
		if (world->tutorialPage < 5) {
			world->tutorialPage++;
		}

	}
	if (Input::wasKeyPressed(SDL_SCANCODE_LEFT)) {
		if (world->tutorialPage!=0) {
			world->tutorialPage--;
		}

	}
	if (Input::wasKeyPressed(SDL_SCANCODE_A)) {
		
		if (world->tutorialPage ==5) {
			Game::instance->currentStage = eStages::STAGEPLAY;
			world->tutorialPage = 0;
			world->currentSound->stop();
			Sleep(150);
		}

	}
}

