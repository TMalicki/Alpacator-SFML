#include "LoadToGame.h"

void LoadToGame::loadItems()
{
	loadWeaponItems();
	loadArmorItems();
	loadPotionItems();
}

Items* LoadToGame::getRandomItem()
{
	int itemTypeChoose = rand() % 300 + 1; //from 1 to 3
	Items* temp{};

	if (itemTypeChoose < 100)
	{
		int random = rand() % atkNumItems;
		temp = atkItems[random]->copyItems();
	}
	else if (itemTypeChoose >= 100 && itemTypeChoose < 200)
	{
		int random = rand() % defNumItems;
		temp = defItems[random]->copyItems();
	}
	else if (itemTypeChoose >= 200)
	{
		int random = rand() % potNumItems;
		temp = potItems[random]->copyItems();
	}
	return temp;
}

std::vector<Items*> LoadToGame::generateItemsInChests()
{
	//itemsInChestsAmount = rand() % 5 + 1;
	std::vector<Items*> itemsList;
	for (int j = 0; j < itemsInChestsAmount; j++)
	{
		itemsList.push_back(getRandomItem());
	}

	return itemsList;
}

void LoadToGame::loadWeaponItems()
{
	///atk/def/agility/stamina/hp/durability
	//atkItems.push_back(new Dagger("Carrot", 5, 1, 3, 1, 0, 5));
	atkItems.push_back(new Dagger("Carrot Sword", 6, 3, 2, 0, 0, 5));
	//atkItems.push_back(new Dagger("Broken Leg", 7, 2, 2, 0, 4));
	atkItems.push_back(new Axe("Mjolnir", 13, 1, 5, 0, 2));
	atkNumItems = atkItems.size();
}

void LoadToGame::loadArmorItems()
{
	///atk/def/agility/stamina/hp/durability
	defItems.push_back(new BreastPlate("Chain Armor", 1, 8, 2, 50, 6));
	defItems.push_back(new Pants("Monk Robe", 0, 5, 5, 16, 8));
	defNumItems = defItems.size();
}

void LoadToGame::loadPotionItems()
{
	///atk/def/agility/stamina/hp
	potItems.push_back(new HealingPot("Health Potion", 0, 0, 0, 100));
	potItems.push_back(new StaminaPot("Mana Potion", 0, 0, 2, 0));
	potNumItems = potItems.size();
}
