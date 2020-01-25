#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "Hero.h"

using namespace std;

class Knight : public Hero
{
private:

public:
	Knight(string n, string prof = "Knight", int h = 120, int s = 5, int d = 10, int agil = 1, int stam = 3) : Hero(n, prof, h, s, d, agil, stam) {}; // dlaczego w liscie inicjalizacyjnej nie moge dodac np atrybutu strength!?!?!?!?!
	~Knight() {};
	virtual void getName() const { cout << name; };
	void check() { cout << "Nothing"; }
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