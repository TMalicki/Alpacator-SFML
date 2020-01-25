#include "Armor.h"
#include "Pants.h"

void Pants::getLook()
{
	// TODO: insert return statement here
	if (name == "Monk Robe") TItem.loadFromFile("images/monkRobe.png");


	SItem.setTexture(TItem);
	SItem.setOrigin(25, 25);
}
