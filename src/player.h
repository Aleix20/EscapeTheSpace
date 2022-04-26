#ifndef PLAYER_H
#define PLAYER_H



#include "sprite.h"

class World;

class Player {
	enum PLAYER_DIR {
		RIGHT = 0,
		LEFT = 1
	};

public:
	Vector2 pos;
	bool isMoving;
	PLAYER_DIR dir = PLAYER_DIR::RIGHT;
	Sprite image;
	float animSpeed = 3.0f;
	float moveSpeed = 50.0f;

	Player();
	Player(Sprite sprite, Vector2 posPlayer, bool isMoving);

	void moving( Vector2 oldPlayerPos);
	void updatePos(Vector2 currentPos, World* world);
	void renderPlayer(Image* framebuffer, float time);
};
#endif