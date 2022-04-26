#ifndef STAGEMENU_H
#define STAGEMENU_H
#include "stage.h"
#include "input.h"
class StageMenu:public Stage
{
public:
	Vector2 menuRec = Vector2(48,49);
	Vector2 menuRecHW =Vector2(60,10);
	int option = 0;
	StageMenu();
	virtual void render(Image* framebuffer, World* world, float* time) override; //empty body
	virtual void update(double seconds_elapsed, World* world) override; //empty body

};
#endif

