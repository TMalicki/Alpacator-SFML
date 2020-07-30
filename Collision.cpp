#include "Collision.h"

bool Collision::isCollided(::Map& Map, int counter, ::Hero* Hero)
{
	if (Hero->getSprite().getGlobalBounds().intersects(Map.getWallSprite()[counter].getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool Collision::isCollided(::Map& Map, int mapPos, list<Chests>::iterator& Chest)
{
	if (Chest->getSprite().getGlobalBounds().intersects(Map.getWallSprite()[mapPos].getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool Collision::isCollided(::Map& Map, int counter, list<Monsters*>::iterator& Monster)
{
	if ((*Monster)->getSprite().getGlobalBounds().intersects(Map.getWallSprite()[counter].getGlobalBounds()))
	{
		return true;
	}
	else return false;
}



bool Collision::isCollided(::list<Chests>::iterator& Chest, ::Hero* Hero)
{
	if (Hero->getSprite().getGlobalBounds().intersects(Chest->getSprite().getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool Collision::isCollided(list<Chests>::iterator& Chest, list<Chests>::iterator& prevChest)
{
	if (Chest->getSprite().getGlobalBounds().intersects(prevChest->getSprite().getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool Collision::isCollided(::Items* Item, ::sf::RectangleShape& Sprite)
{
	if (Item->getItemsSprite().getGlobalBounds().intersects(Sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Collision::isCollided(::list<Monsters*>::iterator& Monster, ::Hero* hero)
{
	if (hero->getSprite().getGlobalBounds().intersects((*Monster)->getSprite().getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool Collision::isCollided(::list<Chests>::iterator& Chest, ::list<Monsters*>::iterator& Monster)
{
	if (Chest->getSprite().getGlobalBounds().intersects((*Monster)->getSprite().getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool Collision::isCollided(::list<Monsters*>::iterator& Monster, ::list<Monsters*>::iterator& prevMonster)
{
	if ((*Monster)->getSprite().getGlobalBounds().intersects((*prevMonster)->getSprite().getGlobalBounds()))
	{
		return true;
	}
	else return false;
}
