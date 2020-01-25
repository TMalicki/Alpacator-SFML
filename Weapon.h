#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "Items.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Weapon : public Items
{
private:
	string type;
public:
	Weapon(string t = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, int durab = 0) : type(t), Items(atk, def, agil, stam, hp, durab) {};
	~Weapon() {};

	virtual string getType() const { return type; };
	virtual string getName() const = 0;
	virtual void getLook() = 0;
	virtual Weapon* copyItems() const = 0;
};

#endif 