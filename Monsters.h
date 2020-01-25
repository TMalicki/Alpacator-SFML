#ifndef MONSTERS_H
#define MONSTERS_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Items.h"

using namespace std;

class Monsters
{
protected:
	int lvl;
	int exp_gain;
	int hp;
	int currentHp;
	int strength;
	int defence;
	int agillity;
	string look;
	int stamina;
	
	sf::Texture TMonster;
	sf::Sprite SMonster;
public:
	Monsters(int l = 0, int exp = 0, int h = 0, int str = 0, int def = 0, int agil = 0, int stam = 3) : lvl(l), exp_gain(exp), hp(h), strength(str), defence(def), agillity(agil), stamina(stam) {};
	virtual ~Monsters() {};

	virtual void getLook() = 0;	
	virtual string getType() const = 0;

	void setStrength(int x) { strength = x; };
	int getStrength() const { return strength; };

	void setDefence(int x) { defence = x; };
	int getDefence() const { return defence; };

	void setAgillity(int x) { agillity = x; };
	int getAgillity() const { return agillity; };

	void setHp(int x) { hp = x; };
	int getHp() const { return hp; };

	void setCurrHp(int x) { currentHp = x; };
	int getCurrHp() const { return currentHp; };

	virtual void setLvl(int x) { lvl = x; };
	virtual int getLvl() const { return lvl; };

	virtual void setStamina(int x) { stamina = x; };
	virtual int getStamina() const { return stamina; };

	//sf::Sprite& getItemsSprite() { return SItem; };
	//sf::Texture& getItemsTexture() { return TItem; };

	//void setItemsSprite(sf::Sprite sprites) { SItem = sprites; };
	//void setItemsTexture(sf::Texture texture) { TItem = texture; };
	//void setItemSpritePos(int x, int y) { SItem.setPosition(x, y); };

	//sf::Text printStats();
	void setPosition(int pos_x, int pos_y) { SMonster.setPosition(pos_x, pos_y); };
	sf::Sprite& getSprite() { return SMonster; };
};


#endif