#ifndef DAGGER_H
#define DAGGER_H

#include <iostream>
#include "Weapon.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Dagger : public Weapon
{
private:
	string name;
public:
	Dagger(string n = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, int durab = 0, string t = "Dagger") : name(n), Weapon(t, atk, def, agil, stam, hp, durab) {};
	~Dagger() {};

	virtual string getName() const { return name; };
	virtual void getLook();
	virtual Dagger* copyItems() const { return new Dagger(*this); };
};

#endif
