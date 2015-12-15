#include "GameState.h"
#include "Enemy.h"
#include "Bullet.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


void Enemy::update()
{
	GameObject::update(); // Update animations

	Timer += sfw::getDeltaTime();

	fireDelay -= sfw::getDeltaTime();
	if ( fireDelay < 0 )
	{
		//int speed1 = 300;
		//float spray1 = rand() % 2 - 5; /*for making a spray of shots*/
		fireDelay = rateOfFire;
		gs()->makeBullet(x, y, 0, -300, 2.f); // Now we can use this to draw stuff!
	}



	// send it to the right
	if ( rever == false && Timer > 0.5f && x != 750)
	{
		Timer -= 0.5f;
		x += 25;
	}
	// left
	else if (rever == true && Timer > 0.5f && x != 25)
	{
		Timer -= 0.5f;
		x -= 25;
	}
	// down if too far to the left
	if (rever == true && x <= 25 && Timer > 0.5f)
	{
		Timer -= 0.5f;
		rever = false;
		y -= 25;
	}
	// down if too far to the right
	else if (rever == false && x >= 750 && Timer > 0.5f)
	{
		Timer -= 0.5f;
		rever = true;
		y -= 25;
	}


}

void Enemy::onCollision(GameObject &go, float distance)
{
	switch (go.type)
	{
	case ENEMY:
		break;
	case BULLET:
		if (((Bullet*)(&go))->vely > 0)
		{
			isActive = false;
		}
		// Kill the enemy
		break;
	case PLAYER:
		break;
	}
}