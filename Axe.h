#ifndef AXE_H
#define AXE_H

#include <iostream>
#include "Weapon.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Axe : public Weapon
{
private:
	string name;
public:
	Axe(string n = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0, int durab = 0, string t = "Axe") : name(n), Weapon(t, atk, def, agil, stam, hp, durab) {};
	~Axe() {};

	virtual string getName() const { return name; };
	virtual void getLook(sf::Texture&, sf::Sprite&) const;
};

#endif
