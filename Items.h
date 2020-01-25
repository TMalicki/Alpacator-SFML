#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Items
{
private:
	int atk;
	int def;
	int agil;
	int stam;
	int hp;
	int durability;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Text ItemInfo;
	sf::Font font;
public:
	Items(int a = 0, int d = 0, int ag = 0, int st = 0, int h = 0, int dur = 0) : atk(a), def(d), agil(ag), stam(st), hp(h), durability(dur) {};
	~Items() {};

	void setAtk(int a) { atk = a; };
	int getAtk() const { return atk; };

	void setDef(int d) { def = d; };
	int getDef() const { return def; };

	void setAgil(int ag) { agil = ag; };
	int getAgil() const { return agil; };

	int getStamina() const { return stam; };

	int getHp() const { return hp; };

	void setDurability(int dur) { durability = dur; };
	int getDurability() const { return durability; };

	virtual string getType() const = 0;
	virtual string getName() const = 0;

	virtual void getLook(sf::Texture&, sf::Sprite&) const = 0;
	sf::Text printStats();
};

#endif
