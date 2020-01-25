#include "Weapon.h"
#include "Axe.h"

void Axe::getLook()
{
	// TODO: insert return statement here
	if (name == "Mjolnir") TItem.loadFromFile("images/mjolnir.png");


	SItem.setTexture(TItem);
	SItem.setOrigin(25, 25);
}
