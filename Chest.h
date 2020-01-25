#include <iostream>
#include <vector>
#include "Items.h"

using namespace std;

class Chests
{
private:
	vector<int> chestCoord;	// coord of every chest
	vector<Items*> items;
	int itemsAmount;
public:
	Chests(char chSign = 254, int itAmount = 3) : itemsAmount(itAmount) {};
	~Chests() {};

	void DrawChests(sf::Texture&, sf::Sprite&);
	//void setCoord(int x, int y) { chestCoord.push_back(x); chestCoord.push_back(y); };
	//vector<int> getCoord() const { return chestCoord; };

	void setItems(Items* item) { items.push_back(item); };
	vector<Items*> getItems() const { return items; };
};
