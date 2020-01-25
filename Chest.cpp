#include "Chest.h"

void Chests::DrawChests()
{
	TChests.loadFromFile("images/chest.png");
	SChests.setTexture(TChests);
}
