#ifndef SPRITE_H
#define SPRITE_H


#include "includes.h"
#include "image.h"
#include "utils.h"
#include "synth.h"
#include "framework.h"
class Sprite
{
	/*enum sSpriteType {
		PLAYER = 0,
		OBJECT =1,
		EMPTY=-1,
	};*/
private:
	Image sprite;
	//sSpriteType type;
	
	

public:
	int sprite_width, sprite_height;
	Vector2 position;
	Sprite();
	Sprite(const char* file, Vector2 pos, int spriteW, int spriteH);
	void drawSprite(Image* frame, int ax, int ay);
	

};
#endif
