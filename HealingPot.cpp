#include "Potion.h"
#include "HealingPot.h"

void HealingPot::getLook()
{
	// TODO: insert return statement here
	if (name == "Health Potion") TItem.loadFromFile("images/healthPotion.png");


	SItem.setTexture(TItem);
	SItem.setOrigin(25, 25);
}
