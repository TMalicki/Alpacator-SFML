#include "Ball.h"

void Ball::getLook()
{
	// TODO: insert return statement here
	TMonster.loadFromFile("images/monsters/happyBall.png");

	SMonster.setTexture(TMonster);
	//SMonster.setOrigin(25, 25);
}
