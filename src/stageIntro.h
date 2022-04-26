#ifndef STAGEINTRO_H
#define STAGEINTRO_H

#include "stage.h"
#include "input.h"
class StageIntro: public Stage
{
public:
	StageIntro();
	virtual void render(Image* framebuffer, World* world, float* time) override; //empty body
	virtual void update(double seconds_elapsed, World* world) override; //empty body
};

#endif