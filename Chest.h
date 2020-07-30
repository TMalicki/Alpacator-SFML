#pragma once

#include <iostream>
#include <vector>
#include "Items.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Chests
{
private:
	vector<int> chestCoord;	// coord of every chest
	vector<Items*> items;
	int itemsAmount;

	sf::Texture TChests;
	sf::Sprite SChests;
public:
	Chests(char chSign = 254, int itAmount = 3) : itemsAmount(itAmount) {};
	~Chests() {};

	void DrawChests();
	//void setCoord(int x, int y) { chestCoord.push_back(x); chestCoord.push_back(y); };
	//vector<int> getCoord() const { return chestCoord; };

	void setItems(Items* item) { items.push_back(item); };
	void setItems(std::vector<Items*> itemsList) { for (auto item : itemsList) { items.push_back(item); } }
	vector<Items*> getItems() const { return items; };
	sf::Sprite& getSprite() { return SChests; };

	void setPosition(int pos_x, int pos_y) { SChests.setPosition(pos_x, pos_y); };
};
