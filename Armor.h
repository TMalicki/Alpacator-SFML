#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include "Items.h"

using namespace std;

class Armor : public Items
{
private:
	string type;
public:
	Armor(string t = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, int durab = 0) : type(t), Items(atk, def, agil, stam, hp, durab) {};
	~Armor() {};

	virtual string getType() const { return type; };
	virtual string getName() const = 0;
	virtual void getLook(sf::Texture&, sf::Sprite&) const = 0;
};

#endif 