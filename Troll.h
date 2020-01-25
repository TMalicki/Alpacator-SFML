#ifndef TROLL_H
#define TROLL_H

#include <iostream>
#include "Monsters.h"

using namespace std;

class Troll : public Monsters
{
private:
	string type;
public:
	//Monsters(string t = "None", int l = 0, int exp = 0, int h = 0, int str = 0, int def = 0, int agil = 0) : type(t), lvl(l), exp_gain(exp), hp(h), strength(str), defence(def), agillity(agil), coord{ 0,0 } {};
	Troll(int l, int exp, int h = 100, int str = 10, int def = 6, int agil = 3) : type("Troll"), Monsters(l, exp, h + 20 * (l - 1), str + (2 * (l - 1)), def + 0.5 * l, agil + 0.25 * l) {};
	~Troll() {};

	virtual void getLook();
	virtual string getType() const { return type; };
};


#endif

