#pragma once

#include <iostream>
#include "Hero.h"
#include "Monsters.h"
#include "Map.h"
#include "Chest.h"
#include <list>

class Collision
{
private:
	bool collided;
public:
	Collision() { collided = false; }
	bool isCollided(::Map&, int, ::Hero*);
	bool isCollided(::Map&, int, ::list<Chests>::iterator&);
	bool isCollided(::Map&, int, list<Monsters*>::iterator&);

	bool isCollided(::list<Chests>::iterator&, ::Hero*);
	bool isCollided(::list<Chests>::iterator&, ::list<Chests>::iterator&);
	bool isCollided(::Items*, ::sf::RectangleShape&);
	bool isCollided(::list<Monsters*>::iterator&, ::Hero*);
	bool isCollided(::list<Chests>::iterator&, ::list<Monsters*>::iterator&);
	bool isCollided(::list<Monsters*>::iterator&, ::list<Monsters*>::iterator&);

	void resetCollision() { collided = false; }

	void collisionSet() { collided = true; }
	bool checkIfAlreadyCollided() { return collided; }
};