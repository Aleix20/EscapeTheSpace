#ifndef STAGEOUTRO_H
#define STAGEOUTRO_H
#include "stage.h"
#include "input.h"
class StageOutro:public Stage
{
public:
	StageOutro();
	virtual void render(Image* framebuffer, World* world, float* time) override; //empty body
	virtual void update(double seconds_elapsed, World* world) override; //empty body
};
#endif
