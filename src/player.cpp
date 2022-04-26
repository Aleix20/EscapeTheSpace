#include "player.h"
#include "world.h"
Player::Player()
{
}
Player::Player(Sprite sprite, Vector2 posPlayer, bool isMoving)
{
	this->image = sprite;
	this->pos = posPlayer;
	this->isMoving = false;
}
void Player::moving( Vector2 oldPlayerPos) {

	//Checking which direction the player is moving to animate
	if (oldPlayerPos.x != this->pos.x || oldPlayerPos.y != this->pos.y) {
		if (oldPlayerPos.x >=0) {
			this->dir = PLAYER_DIR::RIGHT;
		}
		else {
			this->dir = PLAYER_DIR::LEFT;
		}
		this->isMoving = true;
	}
	else {
		this->isMoving = false;
	}
}
void Player::updatePos(Vector2 currentPos, World* world)
{
	//Target point for collisions (cube)
	Vector2 target = pos + currentPos ;
	Vector2 target1 = target - Vector2(3, 0);
	Vector2 target2 = target - Vector2(3,-3);
	Vector2 target3 = target - Vector2(-3, -3);
	Vector2 target4 = target - Vector2(-3, 0);
	
	if (world->isValid(target1)&& world->isValid(target2) && world->isValid(target3) && world->isValid(target4)) {
		pos = target;
		image.position = pos - Vector2(5,13);

	}
	else if (world->isValid(Vector2(target1.x, pos.y)) && world->isValid(Vector2(target2.x, pos.y)) && world->isValid(Vector2(target3.x, pos.y))
		&& world->isValid(Vector2(target4.x, pos.y))) {
		pos = Vector2(target.x, pos.y);
		image.position = pos - Vector2(5, 13);

	}
	else if (world->isValid(Vector2(pos.x, target1.y)) && world->isValid(Vector2(pos.x, target2.y)) && world->isValid(Vector2(pos.x, target3.y))
		&& world->isValid(Vector2(pos.x, target4.y))) {
		pos = Vector2(pos.x, target.y);
		image.position = pos - Vector2(5, 13);

	}
	
}

void Player::renderPlayer(Image* framebuffer, float time)
{
	//animation of the player
	int start_x = (int(time * animSpeed) % 4) * this->image.sprite_width;
	start_x = this->isMoving ? start_x : 0;

	int start_y = (int)this->dir * this->image.sprite_height;
	this->image.drawSprite(framebuffer,start_x,start_y);
}
