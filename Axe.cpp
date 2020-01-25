#include "Weapon.h"
#include "Axe.h"

void Axe::getLook(sf::Texture& texture, sf::Sprite& sprite) const
{
	// TODO: insert return statement here
	if (name == "Mjolnir") texture.loadFromFile("images/mjolnir.png");


	sprite.setTexture(texture);
	sprite.setOrigin(25, 25);
}
