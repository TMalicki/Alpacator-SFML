#ifndef BREASTPLATE_H
#define BREASTPLATE_H

#include <iostream>
#include "Armor.h"
#include <SFML/Graphics.hpp>

using namespace std;

class BreastPlate : public Armor
{
private:
	string name;
public:
	BreastPlate(string n = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, int durab = 0, string t = "Breast Plate") : name(n), Armor(t, atk, def, agil, stam, hp, durab) {};
	~BreastPlate() {};

	virtual string getName() const { return name; };
	virtual void getLook();
	virtual BreastPlate* copyItems() const { return new BreastPlate(*this); };
};

#endif
