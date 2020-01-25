#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include "Hero.h"

using namespace std;

class Mage : public Hero {
protected:

public:
	Mage(string n, string prof = "Mage", int h = 80, int s = 3, int d = 3, int agil = 5, int stam = 3) : Hero(n, prof, h, s, d, agil, stam) {}; // dlaczego w liscie inicjalizacyjnej nie moge dodac np atrybutu strength!?!?!?!?!
	~Mage() {};
	virtual void getName() const { cout << name; };

	/*
	virtual void setStrength(int x) { strength = x; };
	virtual int getStrength() const { return strength; };
	virtual void setDefence(int x) { defence = x; };
	virtual int getDefence() const { return defence; };
	virtual void setAgillity(int x) { agillity = x; };
	virtual int getAgillity() const { return agillity; };
	virtual void setHp(int x) { hp = x; };
	virtual int getHp() const { return hp; };
	*/
};

#endif
