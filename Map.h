#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Map
{
private:
	// map dimension
	int HEIGH;
	int WIDTH;
	int wallSize;	// 50 px

	// map container
	//vector<sf::Sprite> map;
public:
	// set map dimension
	Map(int H = 600, int W = 800, int wSize = 50);
	~Map() {};

	// getter methods
	int get_heigh() { return HEIGH; };	// getter for heigh dimension
	int get_width() { return WIDTH; };	// getter for width dimension
	int get_wallSize() { return wallSize; };

	void Get_title(sf::RenderWindow&, sf::Sprite&);
	void Get_lvl1_map(sf::Texture&, vector<sf::Sprite>&, sf::Texture&, sf::Sprite&);				// put map1 into "map" container

	// display map container
//	void map_disp(vector<sf::Sprite>);
	// method to get map container
//	vector<string> get_map() { return map; };
	// method to set on map container certain sign - to put on map chests, monsters etc
//	void set_OnMap(int x, int y, char z) { map[y][x] = z; };
	// disp exact sign (without putting into map container)
//	void disp_OnMap(int x, int y, char z);
//	void set_offset(int x, int y) { x_offset = x; y_offset = y; };

	// void load_map(vector<string> (*fun)());
};


/*
class Map
{
private:
	// map dimension
	int HEIGH;
	int WIDTH;

	// set offset for game console
	int y_offset;
	int x_offset;

	// map container
	vector<string> map;
	vector<string> title;
public:

	// set map dimension
	Map(int H = 17, int W = 27, int YOFF = 2, int XOFF = 5) { HEIGH = H; WIDTH = W; y_offset = YOFF; x_offset = XOFF; map.push_back(""); title.push_back(""); };
	~Map() {};

	// GoTo coord of map method
	void gotoxy(int x, int y);

	// getter methods
	int get_heigh() { return HEIGH; };	// getter for heigh dimension
	int get_width() { return WIDTH; };	// getter for width dimension
	void Get_title();
	void Get_intro_map();
	void Get_lvl1_map();				// put map1 into "map" container
	void Get_lvl2_map();

	// display map container
	void map_disp();
	// method to get map container
	vector<string> get_map() { return map; };
	// method to set on map container certain sign - to put on map chests, monsters etc
	void set_OnMap(int x, int y, char z) { map[y][x] = z; };
	// disp exact sign (without putting into map container)
	void disp_OnMap(int x, int y, char z);
	void set_offset(int x, int y) { x_offset = x; y_offset = y; };

	// void load_map(vector<string> (*fun)());
};
*/

#endif





