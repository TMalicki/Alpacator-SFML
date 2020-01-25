#ifndef PANTS_H
#define PANTS_H

#include <iostream>
#include "Armor.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Pants : public Armor
{
private:
	string name;
public:
	Pants(string n = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, int durab = 0, string t = "Pants") : name(n), Armor(t, atk, def, agil, stam, hp, durab) {};
	~Pants() {};

	virtual string getName() const { return name; };
	virtual void getLook(sf::Texture&, sf::Sprite&) const;
};

#endif
