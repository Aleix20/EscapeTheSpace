#ifndef STAGEPLAY_H
#define STAGEPLAY_H
#include "stage.h"
#include "world.h"
#include "input.h"

class StagePlay: public Stage
{
public:
	StagePlay();
	virtual void render(Image* framebuffer, World* world, float* time) override; //empty body
	virtual void update(double seconds_elapsed, World* world) override; //empty body
};
#endif
