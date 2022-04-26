#include "sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(const char* file, Vector2 pos, int spriteW, int spriteH) {
	this->sprite.loadTGA(file);
	this->position = pos;
	this->sprite_height = spriteH;
	this->sprite_width = spriteW;
}

void Sprite::drawSprite(Image* frame, int ax, int ay)
{
	frame->drawImage(this->sprite, this->position.x, this->position.y, Area(ax,ay, this->sprite_width, this->sprite_height));
}

