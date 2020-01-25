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

void Map::Get_lvl1_map(sf::Texture& wall, vector<sf::Sprite>& lvl1Map, sf::Texture& Tfloor, sf::Sprite& floor)
{

	wall.loadFromFile("images/wall.jpg");
	Tfloor.loadFromFile("images/floorFULL.jpg");

	sf::Sprite temp;
	temp.setTexture(wall);
	floor.setTexture(Tfloor);

	//sf::Sprite FLtemp;
	//FLtemp.setTexture(floor);
;
	int counter = 0;
	/*
	for (int i = 0; i < WIDTH / wallSize; i++)
	{
		for (int j = 0; j < HEIGH / wallSize; j++)
		{
			lvl1Map.push_back(FLtemp);
			lvl1Map[counter].setPosition(i * wallSize, j * wallSize);
			counter++;
		}
	}
	counter = 0;
	*/

	for (int i = 0; i < WIDTH/wallSize; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(i*wallSize, 0);
		counter++;
	}

	for (int i = 0; i < WIDTH / wallSize; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(i * wallSize, HEIGH - wallSize);
		counter++;
	}

	for (int i = 1; i < (HEIGH / wallSize) - 1; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(0, i * wallSize);
		counter++;
	}

	for (int i = 1; i < (HEIGH / wallSize) - 1; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(WIDTH - wallSize, i * wallSize);
		counter++;
	}

	for (int i = 1; i < 10; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(100, i * wallSize + 50);
		counter++;
	}

	for (int i = 1; i < 5; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(350, i * wallSize + 150);
		counter++;
	}

	for (int i = 1; i < 6; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(600, i * wallSize + 0);
		counter++;
	}

	for (int i = 1; i < 5; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(i * wallSize + 350, 250);
		counter++;
	}

	lvl1Map.push_back(temp);
	lvl1Map[counter].setPosition(700, 250);
	counter++;
	lvl1Map.push_back(temp);
	lvl1Map[counter].setPosition(350, 450);
	counter++;
	lvl1Map.push_back(temp);
	lvl1Map[counter].setPosition(350, 500);
	counter++;

	for (int i = 1; i < 6; i++)
	{
		lvl1Map.push_back(temp);
		//lvl1Map[counter] = temp;
		lvl1Map[counter].setPosition(i * wallSize + 100, 100);
		counter++;
	}

	lvl1Map.push_back(temp);
	lvl1Map[counter].setPosition(150, 350);
	counter++;
	lvl1Map.push_back(temp);
	lvl1Map[counter].setPosition(200, 350);
	counter++;
	lvl1Map.push_back(temp);
	lvl1Map[counter].setPosition(300, 350);
	counter++;
	lvl1Map.push_back(temp);
	lvl1Map[counter].setPosition(350, 350);
	counter++;
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