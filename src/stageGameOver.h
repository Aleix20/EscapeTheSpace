#ifndef STAGEGAMEOVER_H
#define STAGEGAMEOVER_H
#include "stage.h"
#include "input.h"
class StageGameOver :public Stage
{
public:
	StageGameOver();
	virtual void render(Image* framebuffer, World* world, float* time) override; //empty body
	virtual void update(double seconds_elapsed, World* world) override; //empty body
};
#endif
