#include "GameState.h"
#include "Player.h"
#include "Bullet.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


void Player::update()
{



	GameObject::update(); // Update animations



	fireDelay -= sfw::getDeltaTime();
	// example of switching between animations
	if (sfw::getKey(KEY_SPACE) && fireDelay < 0)
	{

		fireDelay = rateOfFire;
		gs()->makeBullet(x, y, 0, 300, 2.f); // Now we can use this to draw stuff!
	}




	//x = sfw::getMouseX();
	//y = sfw::getMouseY();

	float sdt = sfw::getDeltaTime() * speed;
	//if (sfw::getKey('W')) y += sdt; // Euler integration
	//if (sfw::getKey('S')) y -= sdt;
	if (sfw::getKey('A')) x -= sdt;
	if (sfw::getKey('D')) x += sdt;
}

void Player::onCollision(GameObject &go, float distance)
{
	switch (go.type)
	{
	case PLAYER:
		break;
	case BULLET:
		if (((Bullet*)(&go))->vely < 0)
			animationName = "Dwead";
			//!isActive;
		// Kill the player
		break;
	case ENEMY:
		break;
	}
}