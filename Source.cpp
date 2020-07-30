#include <iostream>
#include "App.h"


int main()
{
	int globalWidth = 800;
	int globalHeight = 700;

	sf::RenderWindow window(sf::VideoMode(globalWidth, globalHeight), "Alpakator");
	sf::Event event;
	App play;

	play.game(window, event);	
}

