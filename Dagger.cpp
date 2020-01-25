#include "Weapon.h"
#include "Dagger.h"

void Dagger::getLook()
{
	// TODO: insert return statement here
	if (name == "Carrot Sword") TItem.loadFromFile("images/carrotSword.png");

	
	SItem.setTexture(TItem);
	SItem.setOrigin(25, 25);
}

