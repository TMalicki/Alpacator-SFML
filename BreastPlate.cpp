#include "Armor.h"
#include "BreastPlate.h"

void BreastPlate::getLook()
{
	// TODO: insert return statement here
	if (name == "Chain Armor") TItem.loadFromFile("images/ChainArmor.png");


	SItem.setTexture(TItem);
	SItem.setOrigin(25, 25);
}
