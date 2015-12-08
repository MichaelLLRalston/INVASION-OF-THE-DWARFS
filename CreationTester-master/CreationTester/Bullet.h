#pragma once
#include "GameObject.h"
#include "GameState.h"
#include "sfwdraw.h"

/*
Bullet class!

Mostly copied from player.

Moves in one direction only- no user input.
Most of the gameobjects will follow a similar pattern!
*/

class Bullet : public GameObject
{

public:
	float velx, vely; // velocity of our bullet
	float lifetime; // how long it lasts

	Bullet(float a_x, float a_y, float dx, float dy, float lifespan)
	{
		type = BULLET;
		textureName = "pBullet";
		animationName = "PEW!";
		x = a_x;
		y = a_y;

		velx = dx;
		vely = dy;

		lifetime = lifespan;
	}

	virtual void onCollision(GameObject &go, float distance)
	{
		// we could react to collisions here
	}

	virtual void update()
	{
		GameObject::update(); // go ahead and update the base gameObject class
		lifetime -= sfw::getDeltaTime();
		isActive = lifetime > 0; // the bullet is no longer active when the lifetime reduces to 0

								 // Euler Integration to move our bullet
		x += velx * sfw::getDeltaTime();
		y += vely * sfw::getDeltaTime();
	}

};