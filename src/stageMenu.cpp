#include "stageMenu.h"
#include "game.h"

StageMenu::StageMenu()
{
}

void StageMenu::render(Image* framebuffer, World* world, float* time)
{
	framebuffer->drawImage(world->background,0,0);
	framebuffer->drawRectangle(this->menuRec.x,this->menuRec.y,this->menuRecHW.x,this->menuRecHW.y, Color::WHITE, false);

	framebuffer->drawText("Jugar", 60, 50, world->font);
	framebuffer->drawText("Tutorial", 50, 60, world->font);
}

void StageMenu::update(double seconds_elapsed, World* world)
{
	if (Input::wasKeyPressed(SDL_SCANCODE_DOWN)) {
		if (option !=1) {
			this->menuRec.y += 11;
			option++;
		}
		
	}
	if (Input::wasKeyPressed(SDL_SCANCODE_UP)) {
		if (option != 0) {
			this->menuRec.y -= 11;
			option--;
		}
		
	}
	if (Input::wasKeyPressed(SDL_SCANCODE_A)) {
		if (option==0) {
			Game::instance->currentStage = eStages::STAGEPLAY;
			option = 0;
			world->currentSound->stop();
			Sleep(150);
		}
		else {
			Game::instance->currentStage = eStages::STAGEINTRO;
			this->menuRec.y -= 11;
			option = 0;
		}
	}
	
}
