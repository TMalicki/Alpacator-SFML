#include "Items.h"

sf::Text Items::printStats()
{
	font.loadFromFile("fonts/QuiteMagical.ttf");
	ItemInfo.setFont(font);
	ItemInfo.setCharacterSize(20);

	ItemInfo.setString(this->getName());
	ItemInfo.setOrigin(0, 10);
	ItemInfo.setPosition(420, 307);

	return ItemInfo;
}
