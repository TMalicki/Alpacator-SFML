#include "Troll.h"

void Troll::getLook()
{
	// TODO: insert return statement here
	TMonster.loadFromFile("images/monsters/spider.png");

	SMonster.setTexture(TMonster);
	//SMonster.setOrigin(25, 25);
}
