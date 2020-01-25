#ifndef BARBARIAN_H
#define BARBARIAN_H

#include <iostream>
#include "Hero.h"

using namespace std;

class Barbarian : public Hero {
protected:

public:
	Barbarian(string n, string prof = "Barbarian", int h = 100, int s = 9, int d = 4, int agil = 3, int stam = 3) : Hero(n, prof, h, s, d, agil, stam) {}; // dlaczego w liscie inicjalizacyjnej nie moge dodac np atrybutu strength!?!?!?!?!
	~Barbarian() {};
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
