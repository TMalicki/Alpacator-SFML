#include "APP.h"
#include <time.h>
#include <vector>
#include <Windows.h>
#include <conio.h>


void App::game(sf::RenderWindow& window, sf::Event& event)
{
	/// settings ///
	srand(time(NULL));
	window.setFramerateLimit(60);

	/// map ///
	Map::Map(global_y, global_x);
	Map.Get_title(window, StartScreen);

	/// local variables for moving ///
	int dir[2] {0,0};

	/// load items into memory ///
	setArmorItems();
	setWeaponItems();
	setPotionItems();

	/// start game window ///
	startGame(window, event);

	/// main loop ///
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			/// moving - it should be inside hero class?
			getArrowKey(dir);

			/// getting chests ///

			for (list<Chests>::iterator itr = Chest.begin(); itr != Chest.end(); itr++)
			{
				if (collision(itr, Hero))
				{
					Hero->getFromChest(itr->getItems());
					Chest.erase(itr);
					break;
				}
			}

			/// moving character or highlighted square
			if (inventory_open == false)
				{
					Hero->MoveCharacter(squarePixSize * dir[0], squarePixSize * dir[1]);	/// move character
				}
			else if (inventory_open == true)
				{
					ShighlightItem.move(dir[0] * 53, dir[1] * 53);	/// move highlighted square
					int counter = 0;
					for (int i = 0; i < SHeroItems.size(); i++)
					{
						if (ShighlightItem.getGlobalBounds().intersects(SHeroItems[i].getGlobalBounds()))
						{
							counter++;
						}
					}
					if(counter == 0) ShighlightItem.move(-dir[0] * 53, -dir[1] * 53);
				}

			/// collision 
			for (int i = 0; i < Map.getWallSprite().size(); i++)
			{
				if(collision(Map,i,Hero))
				{
					Hero->MoveCharacter(squarePixSize * (-dir[0]), squarePixSize * (-dir[1]));
				}
			}
			dir[0] = 0; dir[1] = 0;

			/// inventory
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && inventory_open == false)
			{
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {}

				ShighlightItem.setPosition(xPosItem, yPosItem);
				open_inventory();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && inventory_open == true)
			{
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {}
				quit_inventory();
			}

			/// drawing
			if (gameOver == 0)
			{
				window.clear();
				window.draw(Map.getFloorSprite());
				int wallSize = Map.getWallSprite().size();

				for (int i = 0; i < wallSize; i++) window.draw(Map.getWallSprite()[i]);
				window.draw(Hero->getSprite());

				for (list<Chests>::iterator itr = Chest.begin(); itr != Chest.end(); itr++)
				{
					window.draw(itr->getSprite());
				}

				if (inventory_open == true)
				{
					int x = xPosItem; int y = yPosItem - 53;// because it is increase in line 160
					int count = 0;

					window.draw(SInventory);
					window.draw(ShighlightItem);

					///
					vector<Items*> items = Hero->openBackpack();
					int counter = 0;

					for (int i = 0; i < items.size(); i++)
					{
						if (SHeroItems[i].getGlobalBounds().intersects(ShighlightItem.getGlobalBounds()))
						{
							counter = i;
						}
					}	
					///

					for (int i = 0; i < SHeroItems.size(); i++)
					{
						if (i % 4 == 0)
						{
							y += 53;
							count = 0;
						}
						
						SHeroItems[i].setPosition(x + 53 * count, y);
						window.draw(SHeroItems[i]);
						count++;
						window.draw(items[counter]->printStats());
					}
				}
				window.display();
			}
		}
	}
}

void App::startGame(sf::RenderWindow& window, sf::Event& event)
{
	while (window.isOpen() && gameOver != 0)
	{
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				///start game
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}
				///generate items
				//
				///hero maker and map drawer
				Hero = Hero->ChooseProfession(window, event, TProf1, SProf1, TProf2, SProf2, TProf3, SProf3, TProf4, SProf4, TProf5, SProf5);

				Map.Get_lvl1_map();

				Hero->DrawCharacter();
				Generate_Hero();

				chestAmount = 25;

				Chests tempCh;
				for (int i = 0; i < chestAmount; i++)
				{
					Chest.push_back(tempCh);
				}
	
				for (list<Chests>::iterator itr = Chest.begin(); itr != Chest.end(); itr++)
				{
					itr->DrawChests();
				}

				Generate_Chests();
				gameOver = 0;
			}
		}
	}
	window.clear();
	window.draw(Map.getFloorSprite());
	for (int i = 0; i < Map.getWallSprite().size(); i++) window.draw(Map.getWallSprite()[i]);
	window.draw(Hero->getSprite());

	for (list<Chests>::iterator itr = Chest.begin(); itr != Chest.end(); itr++)
	{
		window.draw(itr->getSprite());
	}

	window.display();
}

void App::getArrowKey(int* dir)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//hero->MoveCharacter(Character, -squarePixSize, 0);
		dir[0] = -1;
		dir[1] = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//hero->MoveCharacter(Character, squarePixSize, 0); /*window.display(); */
		dir[0] = 1;
		dir[1] = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//hero->MoveCharacter(Character, 0, -squarePixSize); /*window.display(); */
		dir[0] = 0;
		dir[1] = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//hero->MoveCharacter(Character, 0, squarePixSize); /*window.display(); */
		dir[0] = 0;
		dir[1] = 1;
	}
}

bool App::collision(::Map& Map, int counter, ::Hero* Hero)
{
	if (Hero->getSprite().getGlobalBounds().intersects(Map.getWallSprite()[counter].getGlobalBounds())) return true;
	else return false;
}

bool App::collision(::list<Chests>::iterator& Chest, ::Hero* Hero)
{
	if(Hero->getSprite().getGlobalBounds().intersects(Chest->getSprite().getGlobalBounds())) return true;
	else return false;
}

bool App::collision(::Map& Map, int mapPos, list<Chests>::iterator& Chest)
{
	if (Chest->getSprite().getGlobalBounds().intersects(Map.getWallSprite()[mapPos].getGlobalBounds())) return true;
	else return false;
}

bool App::collision(list<Chests>::iterator& Chest, list<Chests>::iterator& prevChest)
{
	if (Chest->getSprite().getGlobalBounds().intersects(prevChest->getSprite().getGlobalBounds())) return true;
	else return false;
}

void App::Generate_Hero()
{
	//vector<string> current_map = map.get_map();
	int temp_x = 0;
	int temp_y = 0;
	int counter = 0;

	temp_x = rand() % ((global_x / squarePixSize) - 1) + 1;
	temp_x *= squarePixSize;

	temp_y = rand() % ((global_y / squarePixSize) - 1) + 1;
	temp_y *= squarePixSize;

	Hero->setPosition(temp_x, temp_y);

	do
	{
		if (collision(Map, counter, Hero))
		{
			counter = 0;
			temp_x = rand() % ((global_x / squarePixSize) - 1) + 1;
			temp_x *= squarePixSize;

			temp_y = rand() % ((global_y / squarePixSize) - 1) + 1;
			temp_y *= squarePixSize;

			Hero->setPosition(temp_x, temp_y);
		}
		else
		{
			counter++;
		}
	//	cout << Character.getPosition().x << " " << Character.getPosition().y << endl;
	} while (counter < Map.getWallSprite().size());
}

void App::open_inventory()
{
		TInventory.loadFromFile("images/inventory.png");
		SInventory.setTexture(TInventory);
		inventory_open = true;

		vector<Items*> YourItems = Hero->openBackpack();

		sf::Texture tempTItems;
		sf::Sprite tempSItems;
		
		if (!(THeroItems.size() == YourItems.size()))
		{
			int tempSize = THeroItems.size();
			for (int i = 0; i < YourItems.size() - tempSize; i++)
			{
				THeroItems.push_back(tempTItems);
				SHeroItems.push_back(tempSItems);
			}
		}
		
		for (int i = 0; i < YourItems.size(); i++)
		{
			YourItems[i]->getLook(THeroItems[i], SHeroItems[i]);
			THeroItems[i].setSmooth(true);
		}
}

void App::quit_inventory()
{
	inventory_open = false;
}

void App::Generate_Chests()
{
	//vector<Items*>* chestItems = new vector <Items*>[itemAmount];
	int itemTypeChoose;
	//int itemNameChoose;
	
	for (list<Chests>::iterator itr = Chest.begin(); itr != Chest.end(); itr++)
	{
		int temp_x = 0;
		int temp_y = 0;
		bool collided = 0;

		temp_x = rand() % ((global_x / squarePixSize) - 1) + 1;
		temp_x *= squarePixSize;
		temp_y = rand() % ((global_y / squarePixSize) - 1) + 1;
		temp_y *= squarePixSize;

		itr->setPosition(temp_x, temp_y);

		///  INPUT RANDOMLY GENERATED ITEMS INTO CHESTS /////////////////////
		set_itemAmount(rand() % 5 + 1);


		for (int j = 0; j < itemAmount; j++)
		{
			itemTypeChoose = rand() % 300 + 1; //from 1 to 3

			if (itemTypeChoose < 100) itr->setItems(atkItems[rand() % atkNumItems]); //from 0 to 3 (get_atkNumItems()-1)
			else if (itemTypeChoose >= 100 && itemTypeChoose < 200) itr->setItems(defItems[rand() % defNumItems]);
			else if (itemTypeChoose >= 200) itr->setItems(potItems[rand() % potNumItems]);
		}
		///

		do
		{
			collided = 0;
			for (int j = 0; j < Map.getWallSprite().size(); j++)
			{
				if(collision(Map, j, itr) && collided == 0)
				{
					collided = 1;
				}
			}
			if(collision(itr,Hero) && collided == 0)
			{
				collided = 1;
			}

			for (list<Chests>::iterator Previtr = Chest.begin(); Previtr != itr && collided == 0; Previtr++)
			{
				if (collision(itr, Previtr))
				{
					collided = 1;
				}
			}

							
			if(collided == 1)
			{
				temp_x = rand() % ((global_x / squarePixSize) - 1) + 1;
				temp_x *= squarePixSize;

				temp_y = rand() % ((global_y / squarePixSize) - 1) + 1;
				temp_y *= squarePixSize;

				itr->setPosition(temp_x, temp_y);
			}
		} while (collided);
	}
}

void App::setWeaponItems()
{
	///atk/def/agility/stamina/hp/durability
	//atkItems.push_back(new Dagger("Carrot", 5, 1, 3, 1, 0, 5));
	atkItems.push_back(new Dagger("Carrot Sword", 6, 3, 2, 0, 0, 5));
	//atkItems.push_back(new Dagger("Broken Leg", 7, 2, 2, 0, 4));
	atkItems.push_back(new Axe("Mjolnir", 13, 1, 5, 0, 2));
	atkNumItems = atkItems.size();
}

void App::setArmorItems()
{
	///atk/def/agility/stamina/hp/durability
	defItems.push_back(new BreastPlate("Carrot Sword", 1, 8, 2, 50, 6));
	defItems.push_back(new Pants("Carrot Sword", 0, 5, 5, 16, 8));
	defNumItems = defItems.size();
}

void App::setPotionItems()
{
	///atk/def/agility/stamina/hp
	potItems.push_back(new HealingPot("Carrot Sword", 0, 0, 0, 100));
	potItems.push_back(new StaminaPot("Carrot Sword", 0, 0, 2, 0));
	potNumItems = potItems.size();
}


/*

void App::Generate_Stairs()
{
	srand(time(NULL));

	vector<string> current_map = map.get_map();					// view of map
	int temp_x = 0;
	int temp_y = 0;

	do
	{
		temp_x = rand() % map.get_width();
		temp_y = rand() % map.get_heigh();
	} while (current_map[temp_y][temp_x] != ' ');

	map.disp_OnMap(temp_x, temp_y, stairsSign);	// display chest on map
	map.set_OnMap(temp_x, temp_y, stairsSign);	// put chest on map container
	current_map = map.get_map();					// refresh view of map

	stairsCoord[0] = temp_x;
	stairsCoord[1] = temp_y;
}

void App::Generate_Hero()
{
	srand(time(NULL));

	vector<string> current_map = map.get_map();
	int temp_x = 0;
	int temp_y = 0;

	do
	{
		temp_x = rand() % map.get_width();
		temp_y = rand() % map.get_heigh();
	} while (current_map[temp_y][temp_x] != ' ');

	map.disp_OnMap(temp_x, temp_y, heroSign);	// display chest on map

	heroCoord[0] = temp_x;
	heroCoord[1] = temp_y;
}

void App::Hero_Maker()
{

	cout << "Choose your profession:";
	cout << "\n1. Knight";
	cout << "\n2. Barbarian\n\n";

	char choose = _getch();

	switch (choose)
	{
	case '1':
	{
		hero = new Knight("Tom", "Knight");
		hero->setStrength(10);
		hero->setDefence(15);
		hero->setAgillity(5);
		hero->setHp(100);
	}
	break;
	case '2': {
		hero = new Barbarian("Tom", "Barbarian");
		hero->setStrength(15);
		hero->setDefence(7);
		hero->setAgillity(7);
		hero->setHp(100);
	}
			break;
	}

	hero->getName();
	cout << endl;
	hero->getProfession();
	cout << endl << hero->getStrength();
	cout << endl << hero->getDefence();
	cout << endl << hero->getAgillity();
	cout << endl << hero->getHp();

	system("cls");
}


void App::Move()
{
	int temp_x = heroCoord[0];
	int temp_y = heroCoord[1];

	if (_getch() == arrow_key)
	{
		switch (_getch())
		{
		case key_up:
		{
			heroCoord[1]--;
		}
		break;
		case key_down:
		{
			heroCoord[1]++;
		}
		break;
		case key_right:
		{
			heroCoord[0]++;
		}
		break;
		case key_left:
		{
			heroCoord[0]--;
		}
		break;
		}
	}

	if (collisionDetect())
	{
		heroCoord[0] = temp_x;
		heroCoord[1] = temp_y;
	}

	if (higherMap())
	{
		Generate_Lvl2(); // wygeneruj nową mapę
		set_chestAmount(5);	// set amount of chests on map
		Generate_Chests();		// generate chests on map
		Generate_Stairs();		// generate stairs on map
	}

	map.disp_OnMap(temp_x, temp_y, ' ');
	map.disp_OnMap(heroCoord[0], heroCoord[1], heroSign);	// display chest on map
}

bool App::collisionDetect()
{
	vector<string> current_map = map.get_map();

	if ((current_map[heroCoord[1]][heroCoord[0]] == '|') || (current_map[heroCoord[1]][heroCoord[0]] == '-')) return true;
	else false;
}

void App::chestOpen()
{
	vector<string> current_map = map.get_map();

	if (current_map[heroCoord[1]][heroCoord[0]] == chestSign)
	{

		// wrzuć do ekwipunku loota
	}

}

bool App::higherMap()
{
	vector<string> current_map = map.get_map();

	if (current_map[heroCoord[1]][heroCoord[0]] == stairsSign) return true;
	else false;
}
*/