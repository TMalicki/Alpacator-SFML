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
	bool equipped;

	sf::Text ItemInfo;
	sf::Font font;

protected:
	sf::Texture TItem;
	sf::Sprite SItem;

public:
	Items(int a = 0, int d = 0, int ag = 0, int st = 0, int h = 0, int dur = 0) : atk(a), def(d), agil(ag), stam(st), hp(h), durability(dur), equipped(0) {};
	~Items() { cout << "USUNIETO ITEM\n"; };

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

	void setEquip(bool check) { equipped = check; };
	bool getEquip() const { return equipped; };

	virtual string getType() const = 0;
	virtual string getName() const = 0;
	virtual Items* copyItems() const = 0;

	sf::Sprite& getItemsSprite() { return SItem; };
	sf::Texture& getItemsTexture() { return TItem; };

	void setItemsSprite(sf::Sprite sprites) { SItem = sprites; };
	void setItemsTexture(sf::Texture texture) { TItem = texture; };
	void setItemSpritePos(int x, int y) { SItem.setPosition(x, y); };
	
	virtual void getLook() = 0;
	sf::Text printStats();
};

#endif

// czy konstruktor kopiujący może być metoda wirtulną?
