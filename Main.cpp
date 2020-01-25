#include <iostream>
#include <SFML/Graphics.hpp>
#include "App.h"
#include "Map.h"
#include "Hero.h"
#include "Knight.h"
#include "Barbarian.h"

int main()
{
	using namespace std;

	int global_x = 800;
	int global_y = 700;

	//enum Direct{Left, Right, Up, Down};

	sf::RenderWindow window(sf::VideoMode(global_x, global_y), "Alpakator");
	sf::Event event;

	App play;

	play.game(window, event);
	
}

