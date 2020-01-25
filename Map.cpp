#include "Map.h"
#include <Windows.h>

Map::Map(int H, int W, int wSize)
{
	HEIGH = H;
	WIDTH = W;
	wallSize = wSize;
	//window.create(sf::VideoMode(HEIGH, WIDTH), "Alpacator");
}

void Map::Get_title(sf::RenderWindow& window, sf::Sprite& StartScreen)
{
	sf::Texture image;

	image.loadFromFile("images/alpacaStartScreenv2.jpg");
	StartScreen.setTexture(image);

	window.clear();
	window.draw(StartScreen);
	window.display();
}
//	Map.Get_lvl1_map(TWall, SWall, TFloor, SFloor);
void Map::Get_lvl1_map()
{
	TWall.loadFromFile("images/wall.jpg");
	TFloor.loadFromFile("images/floorFULL.jpg");

	sf::Sprite temp;
	temp.setTexture(TWall);
	SFloor.setTexture(TFloor);

	bool lvl1[12][16] = 
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	int counter = 0;
	for (int i = 0; i < HEIGH / wallSize; i++)
	{
		for (int j = 0; j < WIDTH / wallSize; j++)
		{
			SWall.push_back(temp);
			if (lvl1[i][j] == 1)
			{
				SWall[counter].setPosition(j * wallSize, i * wallSize);
			}
			counter++;
		}
	}
}

	/*
	for (int i = 0; i < y_offset; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < HEIGH; i++) {
		for (int k = 0; k < x_offset; k++)
		{
			cout << " ";
		}
		cout << map[i] << endl;
	}

	Get_title();
	gotoxy(4 - x_offset, 1 - y_offset);
	cout << title[0] << endl;
	gotoxy(4 - x_offset, 2 - y_offset);
	cout << title[1] << endl;
	gotoxy(4 - x_offset, 3 - y_offset);
	cout << title[2] << endl;
	gotoxy(4 - x_offset, 4 - y_offset);
	cout << title[3];
	*/

/*
// GoTo coord on map
void Map::gotoxy(int x, int y)
{
	COORD c;
	c.X = x + x_offset;
	c.Y = y + y_offset;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Map::Get_title()
{
	title.clear();
	title.push_back(" ___  _    ___  ___  _ __ ___  ___  ___  ___");
	title.push_back("| . || |  | . \\| . || / /| . ||_ _|| . || . \\");
	title.push_back("|   || |_ |  _/|   ||  \\ |   | | | | | ||   /");
	title.push_back("|_|_||___||_|  |_|_||_\\_\\|_|_| |_| `___'|_\\_\\");
}

void Map::Get_intro_map()
{

}

// put into container map of lvl 1
void Map::Get_lvl1_map()
{
	map.clear();
	map.push_back("+---------+---------------+");
	map.push_back("|         |               |");
	map.push_back("|                         |");
	map.push_back("|                         |");
	map.push_back("|         |               |");
	map.push_back("|         |               |");
	map.push_back("+--   -------   ----------+");
	map.push_back("|         |               |");
	map.push_back("|         |               |");
	map.push_back("|                         |");
	map.push_back("|                         |");
	map.push_back("|         |               |");
	map.push_back("+--   ----+---------------+");
	map.push_back("|                         |");
	map.push_back("|                         |");
	map.push_back("|                         |");
	map.push_back("+-------------------------+");
}

void Map::Get_lvl2_map()
{
	map.clear();
	map.push_back("+---------+---------------+");
	map.push_back("|         |               |");
	map.push_back("|         |               |");
	map.push_back("|         |               |");
	map.push_back("|         |               |");
	map.push_back("|         |               |");
	map.push_back("+---   ---+--   ----------+");
	map.push_back("|         |               |");
	map.push_back("|         |               |");
	map.push_back("|                         |");
	map.push_back("|                         |");
	map.push_back("|         |               |");
	map.push_back("+--   ----+----+----   ---+");
	map.push_back("|              |          |");
	map.push_back("|              |          |");
	map.push_back("|              |          |");
	map.push_back("+--------------+----------+");
}

// display map container
void Map::map_disp()
{
	for (int i = 0; i < y_offset; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < HEIGH; i++) {
		for (int k = 0; k < x_offset; k++)
		{
			cout << " ";
		}
		cout << map[i] << endl;
	}

	Get_title();
	gotoxy(4 - x_offset, 1 - y_offset);
	cout << title[0] << endl;
	gotoxy(4 - x_offset, 2 - y_offset);
	cout << title[1] << endl;
	gotoxy(4 - x_offset, 3 - y_offset);
	cout << title[2] << endl;
	gotoxy(4 - x_offset, 4 - y_offset);
	cout << title[3];
}

// display exact sign on map (for putting on lvl stuff like chests, monsters, etc.)
void Map::disp_OnMap(int x, int y, char z)
{
	gotoxy(x, y);
	cout << z;
}
*/