#include "Armor.h"
#include "Pants.h"

void Pants::getLook(sf::Texture& texture, sf::Sprite& sprite) const
{
	// TODO: insert return statement here
	if (name == "Carrot Sword") texture.loadFromFile("images/carrotSword.png");


	sprite.setTexture(texture);
	sprite.setOrigin(25, 25);
}
