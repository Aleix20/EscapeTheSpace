#ifndef STAGE_H
#define STAGE_H
#include "image.h"
#include "world.h"
class Stage
{
public:
	virtual void render(Image* framebuffer, World* world, float* time) {}; //empty body
	virtual void update(double seconds_elapsed, World* world) {}; //empty body
};
#endif
