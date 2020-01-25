#ifndef POTION_H
#define POTION_H

#include <iostream>
#include "Items.h"

using namespace std;

class Potion : public Items
{
private:
	string type;
public:
	Potion(string t = "Brak", int atk = 0, int def = 0, int agil = 0, int stam = 0, int hp = 0) : type(t), Items(atk, def, agil, stam, hp) {};
	~Potion() {};

	virtual string getType() const { return type; };
	virtual string getName() const = 0;
	virtual void getLook() = 0;
	virtual Potion* copyItems() const = 0;
};

#endif 