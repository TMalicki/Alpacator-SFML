#include "Chest.h"

void Chests::DrawChests(sf::Texture& texture, sf::Sprite& sprite)
{
	texture.loadFromFile("images/chest.png");
	sprite.setTexture(texture);
}
