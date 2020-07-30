#ifndef APP_H
#define APP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "LoadToGame.h"

#include "Map.h"
#include "Hero.h"
#include "Weapon.h"
#include "Dagger.h"
#include "Axe.h"
#include "Armor.h"
#include "BreastPlate.h"
#include "Pants.h"
#include "Potion.h"
#include "HealingPot.h"
#include "StaminaPot.h"
#include "Chest.h"
#include "Monsters.h"
#include "Troll.h"
#include "Ball.h"
#include <list>


using namespace std;

class App {
private:
	int globalWidth;
	int globalHeight;
	int boardSquareSize;
	bool gameOver;

	Collision collision;
	LoadToGame loadToGame;

	Map Map;					
	Hero* Hero;					
	list<Chests> Chest;		
	list<Monsters*> Monster;

	sf::Sprite startScreenSprite;
	sf::Texture heroBarStatsTexture;
	sf::Sprite heroBarStatsSprite;

	sf::Texture inventoryTexture;
	sf::Sprite inventorySprite;

	sf::RectangleShape highlightForActiveItemSquare;	
	sf::RectangleShape highlightForEquippedItemSquare;	

	sf::Text statisticsInfoText;
	sf::Font textFont;



	sf::Texture profession1Texture, profession2Texture, profession3Texture, profession4Texture, profession5Texture; //////////
	sf::Sprite profession1Sprite, profession2Sprite, profession3Sprite, profession4Sprite, profession5Sprite; //////////////////

	bool inventory_open;
	int xPosItem;
	int yPosItem;
	int xMoveItem;
	int yMoveItem;



	int chestAmount;			
	int monsterAmount;

public:
	App() : globalWidth(800), globalHeight(600), boardSquareSize(50), gameOver(1), inventory_open(0), xPosItem(438), yPosItem(356)
	{
		highlightForActiveItemSquare.setSize(sf::Vector2f(40, 40));
		highlightForActiveItemSquare.setOrigin(sf::Vector2f(20, 20));
		highlightForActiveItemSquare.setFillColor(sf::Color::Magenta);

		highlightForEquippedItemSquare.setSize(sf::Vector2f(40, 40));
		highlightForEquippedItemSquare.setOrigin(sf::Vector2f(20, 20));
		highlightForEquippedItemSquare.setFillColor(sf::Color::Green);
	};
	~App() {};

	// MAP //////////////////////////////////////////////////////////////////////////////////
	void game(sf::RenderWindow&, sf::Event&);
	void startGame(sf::RenderWindow&, sf::Event&);
	void getArrowKey(int*);
	void drawEverything(sf::RenderWindow&);
	
	// HERO /////////////////////////////////////////////////////////////////////////////////
	void Generate_Hero();
	void open_inventory();
	void quit_inventory();
	void printStats(sf::RenderWindow&);
	void changeHeroStat(Items*, char);
	void fighting(sf::RenderWindow&, Monsters*);
	/////////////////////////////////////////////////////////////////////////////////////////

	// CHESTS ///////////////////////////////////////////////////////////////////////////////
	void set_chestAmount(int x) { chestAmount = x; };				// set chests amount
	int get_chestAmount() const { return chestAmount; };			// get chests amount
	void Generate_Chests();										// generate chests on the map
	void HeroStatBar();
	/////////////////////////////////////////////////////////////////////////////////////////

	// ITEMS ////////////////////////////////////////////////////////////////////////////////
	
	//void makeItem(string name, a, d, ag, dur);
	/////////////////////////////////////////////////////////////////////////////////////////

	// MONSTERS /////////////////////////////////////////////////////////////////////////////
	void Generate_Monsters(int lvl);
	void set_monstersAmount(int x) { monsterAmount = x; };				// set chests amount
	int get_monstersAmount() const { return monsterAmount; };			// get chests amount
	/////////////////////////////////////////////////////////////////////////////////////////

};
#endif
