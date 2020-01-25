#ifndef ASSASSIN_H
#define ASSASSIN_H

#include <iostream>
#include "Hero.h"

using namespace std;

class Assassin : public Hero 
{
protected:

public://
	Assassin(string n, string prof = "Assassin", int h = 80, int s = 4, int d = 3, int agil = 8, int stam = 5) : Hero(n, prof, h, s, d, agil, stam) {}; // dlaczego w liscie inicjalizacyjnej nie moge dodac np atrybutu strength!?!?!?!?!
	~Assassin() {};
	virtual void getName() const { cout << name; };
//Hero(string n, string prof = "None", int h = 0, int s = 0, int d = 0, int agil = 0, int stam = 0) : name(n), lvl(1), experience(0), hp(h), strength(s), defence(d), agillity(agil), stamina(stam), profession(prof) {};

	/*
	virtual void setStrength(int x) { strength = x; };
	virtual int getStrength() const { return strength; };
	virtual void setDefence(int x) { defence = x; };
	virtual int getDefence() const { return defence; };
	virtual void setAgillity(int x) { agillity = x; };
	virtual int getAgillity() const { return agillity; };
	virtual void setHp(int x) { hp = x; };
	virtual int getHp() const { return hp; };
	virtual void setStam(int x) { stam = x; };
	virtual int getStam() const = { return stam };
	*/
};


#endif
