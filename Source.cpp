#include <iostream>
//#include <SFML/Graphics.hpp>
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
	

	/// zrobić tak by w App.cpp, w metodzie game, nie było tyle rzeczy a np. metoda move(), metoda collision() itp, 
	/// czyli zeby w pollEvent() były same metody, a nie rozwiązania
	
	/// zrobić wybór postaci
	
}

