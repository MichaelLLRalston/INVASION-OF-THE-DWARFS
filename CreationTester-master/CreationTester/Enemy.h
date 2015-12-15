#pragma once
#include "GameObject.h"

/*
See GameObject.h for rationale!


Inheriting from gameobject, we can adopt all of the properties it has and
contribute some of our own. A player, for example, may want to update
it's position based on input.
*/

class GameState;

class Enemy : public GameObject
{
public:
	float speed;
	float fireDelay;
	float rateOfFire;
	float Timer;
	bool rever;

	/*speed      = how fast it travels every frame
	rateOfFire = how fast you can fire
	fireDelay  = time between shots*/
	Enemy() : speed(-300), rateOfFire(1.f), fireDelay(2.f)
	{
		type = ENEMY;
		width = 50; height = 50;
		animationName = "Dwarf";
		textureName = "DwarfFont";

		x = 400;
		y = 600;
	}

	virtual void onCollision(GameObject &go, float distance);
	
	virtual void update(); // Moved to the .cpp!

};