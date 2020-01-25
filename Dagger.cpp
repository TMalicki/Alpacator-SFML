#include "Weapon.h"
#include "Dagger.h"

void Dagger::getLook(sf::Texture& texture, sf::Sprite& sprite) const
{
	// TODO: insert return statement here
	if (name == "Carrot Sword") texture.loadFromFile("images/carrotSword.png");


	sprite.setTexture(texture);
	sprite.setOrigin(25, 25);
}
