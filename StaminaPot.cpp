#include "Potion.h"
#include "StaminaPot.h"

void StaminaPot::getLook()
{
	// TODO: insert return statement here
	if (name == "Mana Potion") TItem.loadFromFile("images/manaPotion.png");


	SItem.setTexture(TItem);
	SItem.setOrigin(25, 25);
}
