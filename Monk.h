#ifndef MONK_H
#define MONK_H

#include <iostream>
#include "Hero.h"

using namespace std;

class Monk : public Hero
{
private:

public:
	Monk(string n, string prof = "Monk", int h = 80, int s = 3, int d = 4, int agil = 4, int stam = 3) : Hero(n, prof, h, s, d, agil, stam) {}; // dlaczego w liscie inicjalizacyjnej nie moge dodac np atrybutu strength!?!?!?!?!
	~Monk() {};
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
	//int setStrength();
	//void getStrength() const;
};

#endif