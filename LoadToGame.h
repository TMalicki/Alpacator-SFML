#pragma once

#include "LoadToGame.h"
#include "HealingPot.h"
#include "StaminaPot.h"
#include "BreastPlate.h"
#include "Pants.h"
#include "Dagger.h"
#include "Axe.h"

class LoadToGame
{
private:
	int itemsInChestsAmount;
	vector<Weapon*> atkItems;
	int atkNumItems;
	vector<Armor*> defItems;
	int defNumItems;
	vector<Potion*> potItems;
	int potNumItems;
public:
	void setItemAmount(int x) { itemsInChestsAmount = x; };			
	int getItemAmount() const { return itemsInChestsAmount; };			

	int getAtkNumItems() { return atkNumItems; };
	int getDefNumItems() { return defNumItems; };
	int getPotNumItems() { return potNumItems; };

	void loadWeaponItems();
	void loadArmorItems();
	void loadPotionItems();

	void loadItems();
	Items* getRandomItem();

	std::vector<Items*> generateItemsInChests();
};