#ifndef HEALINGPOT_H
#define HEALINGPOT_H

#include <iostream>
#include "Potion.h"
#include <SFML/Graphics.hpp>

using namespace std;

class HealingPot : public Potion
{
private:
	string name;
public:
	HealingPot(string n = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, string t = "Healing potion") : name(n), Potion(t, atk, def, agil, stam, hp) {};
	~HealingPot() {};

	virtual string getName() const { return name; };
	virtual void getLook();
	virtual HealingPot* copyItems() const { return new HealingPot(*this); };
};

#endif
