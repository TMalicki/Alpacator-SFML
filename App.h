#ifndef APP_H
#define APP_H

#include <iostream>
#include <SFML/Graphics.hpp>
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
	/// global x-y parameters
	int global_x;
	int global_y;
	/// one square size
	int squarePixSize;

	bool gameOver;

	/// class objects in App class
	Map Map;					// class App has class Map
	Hero* Hero;					// class App has class Hero
	list<Chests> Chest;		// class App has container of chests
	list<Monsters*> Monster;

	/// SPRITES ///////////
	// startScreen sprite
	sf::Sprite StartScreen;
	// bar with hero stats
	sf::Texture THeroBarStats;
	sf::Sprite SHeroBarStats;
	// profession of hero sprites
	sf::Texture TProf1, TProf2, TProf3, TProf4, TProf5;
	sf::Sprite SProf1, SProf2, SProf3, SProf4, SProf5;
	// backpack (not items) sprite
	sf::Texture TInventory;
	sf::Sprite SInventory;
	// not sprite but drawable objects
	sf::RectangleShape ShighlightItem;	// highlighte square for item
	sf::RectangleShape EquippedItem;	// square for equipped items
	// 
	sf::Text StatInfo;
	sf::Font font;
	/// //////////////////////

	bool inventory_open;
	int xPosItem;
	int yPosItem;
	int xMoveItem;
	int yMoveItem;

	int itemAmount;				// amount of items in chests
	vector<Weapon*> atkItems;
	int atkNumItems;
	vector<Armor*> defItems;
	int defNumItems;
	vector<Potion*> potItems;
	int potNumItems;

	int chestAmount;			// amount of chests
	int monsterAmount;

	/// ////////////////////////
	//int totalHeroAtk;
	//int totalHeroDef;
	//int totalHeroAgil;
public:

	// default constructor
	App() : global_x(800), global_y(600), squarePixSize(50), gameOver(1), inventory_open(0), xPosItem(438), yPosItem(356) 
	{
		ShighlightItem.setSize(sf::Vector2f(40, 40));
		ShighlightItem.setOrigin(sf::Vector2f(20, 20));
		ShighlightItem.setFillColor(sf::Color::Magenta);

		EquippedItem.setSize(sf::Vector2f(40, 40));
		EquippedItem.setOrigin(sf::Vector2f(20, 20));
		EquippedItem.setFillColor(sf::Color::Green);
	};
	~App() {};

	// MAP //////////////////////////////////////////////////////////////////////////////////
	void game(sf::RenderWindow&, sf::Event&);
	void startGame(sf::RenderWindow&, sf::Event&);
	void getArrowKey(int*);
	void drawEverything(sf::RenderWindow&);

	bool collision(::Map&, int, ::Hero*);
	bool collision(::list<Chests>::iterator&, ::Hero*);
	bool collision(::Map&, int, ::list<Chests>::iterator&);
	bool collision(::list<Chests>::iterator&, ::list<Chests>::iterator&);
	bool collision(::Items*, ::sf::RectangleShape&);

	bool collision(::Map&, int, ::list<Monsters*>::iterator&);
	bool collision(::list<Monsters*>::iterator&, ::Hero*);
	bool collision(::list<Chests>::iterator&, ::list<Monsters*>::iterator&);
	bool collision(::list<Monsters*>::iterator&, ::list<Monsters*>::iterator&);
	//void startGame();
	//void Generate_Intro() { cout << "Loading map..."; map.Get_intro_map(); system("cls"); map.map_disp(); }
	//void Generate_Lvl1() { cout << "Loading map..."; map.Get_lvl1_map(); system("cls"); map.map_disp(); };	// generate map of exact lvl (make this chosen lvl - not only first)
	//void Generate_Lvl2() { cout << "Loading map..."; map.Get_lvl2_map(); system("cls"); map.map_disp(); }	////// MAKE THIS CHOSEN LVL ON ONLY FIRST !!!!!
	//bool higherMap();
	//void Generate_Stairs();											// generate stairs on the map

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
	void set_itemAmount(int x) { itemAmount = x; };				// set chests amount
	int get_itemAmount() const { return itemAmount; };			// get chests amount
	void setWeaponItems();
	void setArmorItems();
	void setPotionItems();
	int get_atkNumItems() { return atkNumItems; };
	int get_defNumItems() { return defNumItems; };
	int get_potNumItems() { return potNumItems; };
	//void makeItem(string name, a, d, ag, dur);
	/////////////////////////////////////////////////////////////////////////////////////////

	// MONSTERS /////////////////////////////////////////////////////////////////////////////
	void Generate_Monsters(int lvl);
	void set_monstersAmount(int x) { monsterAmount = x; };				// set chests amount
	int get_monstersAmount() const { return monsterAmount; };			// get chests amount
	/////////////////////////////////////////////////////////////////////////////////////////

};
#endif
