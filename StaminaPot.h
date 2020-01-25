#ifndef STAMINAPOT_H
#define STAMINAPOT_H

#include <iostream>
#include "Potion.h"
#include <SFML/Graphics.hpp>

using namespace std;

class StaminaPot : public Potion
{
private:
	string name;
public:
	StaminaPot(string n = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, string t = "Stamina potion") : name(n), Potion(t, atk, def, agil, stam, hp) {};
	~StaminaPot() {};

	virtual string getName() const { return name; };
	virtual void getLook();
	virtual StaminaPot* copyItems() const { return new StaminaPot(*this); };
};

#endif
