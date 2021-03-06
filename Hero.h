#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Items.h"
#include <string>

// character - name, lvl, experience, strength, defence, agility, coord, hp
// inherited class Rogue, Tank, Warrior

using namespace std;

class Hero
{
protected:
	string name;
	int lvl;
	int experience;
	int hp;
	int strength;
	int defence;
	int agillity;
	int stamina;
	string profession;
	vector<Items*> items;

	sf::Texture THero;
	sf::Sprite SHero;

	sf::Text StatInfo;
	sf::Font font;
public:
	Hero(string n, string prof = "None", int h = 0, int s = 0, int d = 0, int agil = 0, int stam = 0) : name(n), lvl(1), experience(0), hp(h), strength(s), defence(d), agillity(agil), stamina(stam), profession(prof) {};
	virtual ~Hero() {};

	virtual void getName() const = 0;
	virtual string getProfession() const { return profession; };

	void setStrength(int x) { strength = x; };
	int getStrength() const { return strength; };
	void setDefence(int x) { defence = x; };
	int getDefence() const { return defence; };
	void setAgillity(int x) { agillity = x; };
	int getAgillity() const { return agillity; };
	void setHp(int x) { hp = x; };
	int getHp() const { return hp; };
	void setStam(int x) { stamina = x; };
	int getStam() const { return stamina; };
	sf::Sprite& getSprite() { return SHero; };

	void DrawCharacter(int heigh = 600, int width = 800);
	void setPosition(int pos_x, int pos_y) { SHero.setPosition(pos_x, pos_y); };


	void MoveCharacter(int change_x, int change_y);
	Hero* ChooseProfession(sf::RenderWindow&, sf::Event&, sf::Texture&, sf::Sprite&, sf::Texture&, sf::Sprite&, sf::Texture&, sf::Sprite&, sf::Texture&, sf::Sprite&, sf::Texture&, sf::Sprite&);
	void getFromChest(vector<Items*>);
	vector<Items*> openBackpack();
	sf::Text printStats();
	//void HeroChooseWheel(sf::Sprite&, int, int, int);
};


#endif