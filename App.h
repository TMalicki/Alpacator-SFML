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
	vector<Chests> Chest;		// class App has container of chests
						
	/// SPRITES ///////////
	// startScreen sprite
	sf::Sprite StartScreen;
	// Wall sprite
	sf::Texture TWall;
	vector<sf::Sprite> SWall;
	// Floor sprite
	sf::Texture TFloor;
	sf::Sprite SFloor;
	// Hero sprite
	sf::Texture THero;
	sf::Sprite SHero;
	// profession of hero sprites
	sf::Texture TProf1, TProf2, TProf3, TProf4, TProf5;
	sf::Sprite SProf1, SProf2, SProf3, SProf4, SProf5;
	// Chest sprites
	sf::Texture TChest;
	vector<sf::Sprite> SChest;
	// backpack (not items) sprite
	sf::Texture TInventory;
	sf::Sprite SInventory;
	// vector of items stored in backpack
	vector<sf::Texture> THeroItems;
	vector<sf::Sprite> SHeroItems;
	// not sprite but drawable object
	sf::RectangleShape ShighlightItem;	// highlite square for item
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
public:

	// default constructor
	App() : global_x(800), global_y(600), squarePixSize(50), gameOver(1), inventory_open(0), xPosItem(438), yPosItem(355) 
	{
		ShighlightItem.setSize(sf::Vector2f(40, 40));
		ShighlightItem.setOrigin(sf::Vector2f(20, 20));
		ShighlightItem.setFillColor(sf::Color::Magenta);
	};
	~App() {};

	// MAP //////////////////////////////////////////////////////////////////////////////////
	void game(sf::RenderWindow&, sf::Event&);
	void startGame(sf::RenderWindow&, sf::Event&);
	void getArrowKey(int*);
	//void startGame();
	//void Generate_Intro() { cout << "Loading map..."; map.Get_intro_map(); system("cls"); map.map_disp(); }
	//void Generate_Lvl1() { cout << "Loading map..."; map.Get_lvl1_map(); system("cls"); map.map_disp(); };	// generate map of exact lvl (make this chosen lvl - not only first)
	//void Generate_Lvl2() { cout << "Loading map..."; map.Get_lvl2_map(); system("cls"); map.map_disp(); }	////// MAKE THIS CHOSEN LVL ON ONLY FIRST !!!!!
	//bool higherMap();
	//void Generate_Stairs();											// generate stairs on the map

	// HERO /////////////////////////////////////////////////////////////////////////////////
	//void Hero_Maker();
	//void Move();
	void Generate_Hero();
	void open_inventory();
	void quit_inventory();
	//bool collisionDetect();
	//void chestOpen();
	/////////////////////////////////////////////////////////////////////////////////////////

	// CHESTS ///////////////////////////////////////////////////////////////////////////////
	void set_chestAmount(int x) { chestAmount = x; };				// set chests amount
	int get_chestAmount() const { return chestAmount; };			// get chests amount
	void Generate_Chests();										// generate chests on the map
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

};
#endif
