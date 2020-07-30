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
	Map::Map(globalHeight, globalWidth);
	Map.Get_title(window, startScreenSprite);

	/// local variables for moving ///

	int dir[2] {0,0};

	/// load items into memory ///
	loadToGame.loadItems();
	
	HeroStatBar();

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
			for (auto itr = Chest.begin(); itr != Chest.end(); itr++)
			{
				if (collision.isCollided(itr, Hero))
				{
					Hero->getFromChest(itr->getItems());
					Chest.erase(itr);
					break;
				}
			}

			/// fighting monsters ///
			for (auto itr = Monster.begin(); itr != Monster.end(); itr++)
			{
				if (collision.isCollided(itr, Hero))
				{
					//fighting();
					fighting(window, *itr);
					Monster.erase(itr);
					break;
				}
			}

			/// moving character or highlighted square
			if (inventory_open == false)
				{
					Hero->MoveCharacter(boardSquareSize * dir[0], boardSquareSize * dir[1]);	/// move character
				}
			else if (inventory_open == true)
				{
					int counter = 0;
					vector<Items*> Backpack = Hero->openBackpack();

					highlightForActiveItemSquare.move(dir[0] * 53, dir[1] * 53);	/// move highlighted square

					for(int i = 0; i<Backpack.size(); i++)
					{
						//if (collision(Backpack[i], ShighlightItem));
						if (Backpack[i]->getItemsSprite().getGlobalBounds().intersects(highlightForActiveItemSquare.getGlobalBounds()))
						{
							counter++;
						}
					}
					if(counter == 0) highlightForActiveItemSquare.move(-dir[0] * 53, -dir[1] * 53);
				}

			/// collision 
			for (int i = 0; i < Map.getWallSprite().size(); i++)
			{
				if(collision.isCollided(Map,i,Hero))
				{
					Hero->MoveCharacter(boardSquareSize * (-dir[0]), boardSquareSize * (-dir[1]));
				}
			}
			dir[0] = 0; dir[1] = 0;

			/// inventory
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && inventory_open == false)
			{
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {}

				highlightForActiveItemSquare.setPosition(xPosItem, yPosItem);
				open_inventory();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && inventory_open == true)
			{
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {}
				quit_inventory();
			}
			if (inventory_open == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}

				vector<Items*> Backpack = Hero->openBackpack();

				for (int i = 0; i < Backpack.size(); i++)
				{
					if (collision.isCollided(Backpack[i], highlightForActiveItemSquare))
					{
						if (Backpack[i]->getEquip() == false)
						{
							bool flag = false;

							string BackpackType = Backpack[i]->getType();

							if (BackpackType == "Dagger" || BackpackType == "Axe")
							{
								for (int j = 0; (j < Backpack.size()); j++)
								{
									if (j != i)
									{
										string tempType = Backpack[j]->getType();
										if ((tempType == "Dagger" || tempType == "Axe") && Backpack[j]->getEquip() == true)
										{
											flag = true;
										}
									}
								}
							}
							else if (BackpackType == "Breast Plate" || BackpackType == "Pants")
							{
								for (int j = 0; (j < Backpack.size()); j++)
								{
									if (j != i)
									{
										string tempType = Backpack[j]->getType();
										if ((tempType == "Breast Plate" || tempType == "Pants") && Backpack[j]->getEquip() == true)
										{
											flag = true;
										}
									}
								}
							}

							if (flag == false)
							{
								Backpack[i]->setEquip(true);
								highlightForEquippedItemSquare.setPosition(highlightForActiveItemSquare.getPosition());
								
								changeHeroStat(Backpack[i],'+');
								//Backpack[i]->getAtk();
							}
						}
						else
						{
							Backpack[i]->setEquip(false);
							changeHeroStat(Backpack[i], '-');
						}
					}
				}
			}

			/// drawing
			if (gameOver == 0)
			{
				drawEverything(window);
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
				Hero = Hero->ChooseProfession(window, event, profession1Texture, profession1Sprite, profession2Texture, profession2Sprite,
						profession3Texture, profession3Sprite, profession4Texture, profession4Sprite, profession5Texture, profession5Sprite);

				Map.Get_lvl1_map();

				Hero->DrawCharacter();
				Generate_Hero();

				chestAmount = 5;

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

				monsterAmount = 5;

				Generate_Monsters(1);

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

	for (list<Monsters*>::iterator itr = Monster.begin(); itr != Monster.end(); itr++)
	{
		window.draw((*itr)->getSprite());
	}

	window.draw(heroBarStatsSprite);
	printStats(window);

	window.display();
}

void App::getArrowKey(int* dir)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {};
		//hero->MoveCharacter(Character, -squarePixSize, 0);
		dir[0] = -1;
		dir[1] = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {};
		//hero->MoveCharacter(Character, squarePixSize, 0); /*window.display(); */
		dir[0] = 1;
		dir[1] = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {};
		//hero->MoveCharacter(Character, 0, -squarePixSize); /*window.display(); */
		dir[0] = 0;
		dir[1] = -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {};
		//hero->MoveCharacter(Character, 0, squarePixSize); /*window.display(); */
		dir[0] = 0;
		dir[1] = 1;
	}
}

void App::drawEverything(sf::RenderWindow& window)
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

	for (list<Monsters*>::iterator itr = Monster.begin(); itr != Monster.end(); itr++)
	{
		window.draw((*itr)->getSprite());
	}

	window.draw(heroBarStatsSprite);
	printStats(window);

	if (inventory_open == true)
	{
		int x = xPosItem; int y = yPosItem - 53;// because it is increase in line 160
		int count = 0;

		window.draw(inventorySprite);
		window.draw(highlightForActiveItemSquare);

		///
		vector<Items*> Backpack = Hero->openBackpack();
		int counter = 0;

		for (int i = 0; i < Backpack.size(); i++)
		{
			//if (SHeroItems[i].getGlobalBounds().intersects(ShighlightItem.getGlobalBounds()))
			if (Backpack[i]->getItemsSprite().getGlobalBounds().intersects(highlightForActiveItemSquare.getGlobalBounds()))
			{
				counter = i;
			}
		}
		///

		for (int i = 0; i < Backpack.size(); i++)
		{
			if (Backpack[i]->getEquip())
			{
				string BackpackType = Backpack[i]->getType();
				sf::Vector2f EquippedItemPos = Backpack[i]->getItemsSprite().getPosition();

				if (BackpackType == "Dagger" || BackpackType == "Axe")
				{
					Backpack[i]->setItemSpritePos(463, 210);
					highlightForEquippedItemSquare.setPosition(EquippedItemPos);
				}
				else if (BackpackType == "Breast Plate" || BackpackType == "Pants")
				{
					Backpack[i]->setItemSpritePos(516, 210);
					highlightForEquippedItemSquare.setPosition(EquippedItemPos);
				}

				window.draw(Backpack[i]->getItemsSprite());
				window.draw(highlightForEquippedItemSquare);
			}
		}

		for (int i = 0; i < Backpack.size(); i++)
		{
			if (i % 4 == 0)
			{
				y += 53;
				count = 0;
			}

			Backpack[i]->setItemSpritePos(x + (53 * count), y);
			window.draw(Backpack[i]->getItemsSprite());
			count++;
			window.draw(Backpack[counter]->printStats());
		}

	}
}

void App::Generate_Hero()
{
	//vector<string> current_map = map.get_map();
	int temp_x = 0;
	int temp_y = 0;
	int counter = 0;

	temp_x = rand() % ((globalWidth / boardSquareSize) - 1) + 1;
	temp_x *= boardSquareSize;

	temp_y = rand() % ((globalHeight / boardSquareSize) - 1) + 1;
	temp_y *= boardSquareSize;

	Hero->setPosition(temp_x, temp_y);

	do
	{
		if (collision.isCollided(Map, counter, Hero))
		{
			counter = 0;
			temp_x = rand() % ((globalWidth / boardSquareSize) - 1) + 1;
			temp_x *= boardSquareSize;

			temp_y = rand() % ((globalHeight / boardSquareSize) - 1) + 1;
			temp_y *= boardSquareSize;

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
		inventoryTexture.loadFromFile("images/inventory.png");
		inventorySprite.setTexture(inventoryTexture);
		inventory_open = true;

		vector<Items*> YourItems = Hero->openBackpack();

		for (int i = 0; i < YourItems.size(); i++)
		{
			YourItems[i]->getLook();
		}
}

void App::quit_inventory()
{
	inventory_open = false;
}

void App::printStats(sf::RenderWindow& window)
{
	textFont.loadFromFile("fonts/QuiteMagical.ttf");
	statisticsInfoText.setFont(textFont);
	statisticsInfoText.setCharacterSize(30);

	//StatInfo.setString(Hero->getProfession());
	statisticsInfoText.setString(to_string(Hero->getHp()) + " / " + to_string(Hero->getHp()));
	statisticsInfoText.setOrigin(0, 15);
	statisticsInfoText.setPosition(100, 628);
	window.draw(statisticsInfoText);

	statisticsInfoText.setString(to_string(Hero->getStrength()));
	statisticsInfoText.setPosition(100, 664);
	window.draw(statisticsInfoText);

	statisticsInfoText.setString(to_string(Hero->getAgillity()));
	statisticsInfoText.setPosition(360, 628);
	window.draw(statisticsInfoText);

	statisticsInfoText.setString(to_string(Hero->getDefence()));
	statisticsInfoText.setPosition(360, 664);
	window.draw(statisticsInfoText);

	statisticsInfoText.setString(to_string(Hero->getStam()));
	statisticsInfoText.setPosition(620, 628);
	window.draw(statisticsInfoText);
}

void App::changeHeroStat(Items* item, char sign)
{
	if (sign == '+')
	{
		int totalCurrentStat = Hero->getStrength() + item->getAtk();
		Hero->setStrength(totalCurrentStat);
		totalCurrentStat = Hero->getDefence() + item->getDef();
		Hero->setDefence(totalCurrentStat);
		totalCurrentStat = Hero->getAgillity() + item->getAgil();
		Hero->setAgillity(totalCurrentStat);
		totalCurrentStat = Hero->getHp() + item->getHp();
		Hero->setHp(totalCurrentStat);
		totalCurrentStat = Hero->getStam() + item->getStamina();
		Hero->setStam(totalCurrentStat);
	}
	else if (sign == '-')
	{
		int totalCurrentStat = Hero->getStrength() - item->getAtk();
		Hero->setStrength(totalCurrentStat);
		totalCurrentStat = Hero->getDefence() - item->getDef();
		Hero->setDefence(totalCurrentStat);
		totalCurrentStat = Hero->getAgillity() - item->getAgil();
		Hero->setAgillity(totalCurrentStat);
		totalCurrentStat = Hero->getHp() - item->getHp();
		Hero->setHp(totalCurrentStat);
		totalCurrentStat = Hero->getStam() - item->getStamina();
		Hero->setStam(totalCurrentStat);

	}
	else
	{
		cout << "Error - wrong sign in changeHeroStat method.\n";
	}
}

void App::fighting(sf::RenderWindow& window, Monsters* Monster)
{
	Monster->setCurrHp(Monster->getHp());
	sf::Texture texture;
	texture.loadFromFile("images/battleScreen.jpg");
	sf::Sprite battleGround;
	battleGround.setTexture(texture);

	sf::Texture texture2;
	texture2.loadFromFile("images/actionScreen.png");
	sf::Sprite actionScreen;
	actionScreen.setTexture(texture2);
	actionScreen.setOrigin(100, 150);
	actionScreen.setPosition(400, 300);

	HeroStatBar();
	sf::Sprite SHero = Hero->getSprite();
	SHero.setScale(3, 3);
	SHero.setPosition(100, 300);
	sf::Sprite SMonster = Monster->getSprite();
	SMonster.setScale(3, 3);
	SMonster.setPosition(550, 200);

	sf::RectangleShape rectangle(sf::Vector2f(140, 50));
	sf::RectangleShape rectWhite(sf::Vector2f(140, 280));

	rectWhite.setFillColor(sf::Color::White);
	rectangle.setFillColor(sf::Color::Black);

	rectWhite.setOrigin(70, 140);
	rectangle.setOrigin(70, 25);

	rectWhite.setPosition(400, 300);
	rectangle.setPosition(400, 185);

	int count = 0;
	bool flag = 1;

	int currentMonsterHp = Monster->getCurrHp();

	while (currentMonsterHp > 0 && flag == 1)
	{
		int dir[2];
		getArrowKey(dir);

		if ((dir[1] == -1) && (count > 0))
		{
			rectangle.move(0, -77);
			dir[1] = 0;
			count--;
		}
		else if ((dir[1] == 1) && (count < 3))
		{
			rectangle.move(0, 77);
			dir[1] = 0;
			count++;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			switch (count)
			{
			case 0:
			{
				currentMonsterHp -= Hero->getStrength();
			}
			break;
			case 1:
			{

			}
			break;
			case 2:
			{

			}
			break;
			case 3:
			{
				if (Hero->getAgillity() > Monster->getAgillity())
				{
					flag = 0;
				}
			}
			break;
			}
		}

		window.clear();
		window.draw(battleGround);
		window.draw(rectWhite);
		window.draw(rectangle);
		window.draw(actionScreen);
		window.draw(heroBarStatsSprite);
		window.draw(SHero);
		window.draw(SMonster);

		window.display();
	}
}

void App::Generate_Chests()
{
	for (list<Chests>::iterator itr = Chest.begin(); itr != Chest.end(); itr++)
	{
		int temp_x = 0;
		int temp_y = 0;
	
		temp_x = rand() % ((globalWidth / boardSquareSize) - 1) + 1;
		temp_x *= boardSquareSize;
		temp_y = rand() % ((globalHeight / boardSquareSize) - 1) + 1;
		temp_y *= boardSquareSize;

		itr->setPosition(temp_x, temp_y);

		///  INPUT RANDOMLY GENERATED ITEMS INTO CHESTS /////////////////////
		loadToGame.setItemAmount(rand() % 5 + 1);
		itr->setItems(loadToGame.generateItemsInChests());

		do
		{
			collision.resetCollision();
			for (int j = 0; j < Map.getWallSprite().size(); j++)
			{
				if (collision.isCollided(Map, j, itr)) collision.collisionSet();
			}
			collision.isCollided(itr, Hero);

			for (list<Chests>::iterator Previtr = Chest.begin(); Previtr != itr && collision.checkIfAlreadyCollided() == false; Previtr++)
			{
				if(collision.isCollided(itr, Previtr)) collision.collisionSet();
			}
						
			if(collision.checkIfAlreadyCollided())
			{
				temp_x = rand() % ((globalWidth / boardSquareSize) - 1) + 1;
				temp_x *= boardSquareSize;

				temp_y = rand() % ((globalHeight / boardSquareSize) - 1) + 1;
				temp_y *= boardSquareSize;

				itr->setPosition(temp_x, temp_y);
			}
		} while (collision.checkIfAlreadyCollided());
	}
}

void App::HeroStatBar()
{
	heroBarStatsTexture.loadFromFile("images/backgroundStats.png");
	heroBarStatsSprite.setTexture(heroBarStatsTexture);
	heroBarStatsSprite.setPosition(0, 600);
}



void App::Generate_Monsters(int lvl)
{
	int monsterTypeChoose;

	for (int i = 0; i < monsterAmount; i++)
	{
		Monster.push_back(new Troll(1,10));
	}

	for (auto itr = Monster.begin(); itr != Monster.end(); itr++)
	{
		int temp_x = 0;
		int temp_y = 0;

		temp_x = rand() % ((globalWidth / boardSquareSize) - 1) + 1;
		temp_x *= boardSquareSize;
		temp_y = rand() % ((globalHeight / boardSquareSize) - 1) + 1;
		temp_y *= boardSquareSize;

		(*itr)->setPosition(temp_x, temp_y);
		
		set_monstersAmount(10);

		monsterTypeChoose = rand() % 200 + 1; //from 1 to 3

		if (monsterTypeChoose < 100)
		{
			*itr = (new Troll(lvl, 10));
		}
		else if (monsterTypeChoose >= 100 && monsterTypeChoose < 200)
		{
			*itr = (new Ball(lvl, 10));
		}

		for (list<Monsters*>::iterator itr2 = Monster.begin(); itr2 != Monster.end(); itr2++)
		{
			(*itr2)->getLook();
		}

		do
		{
			collision.resetCollision();
			for (int j = 0; j < Map.getWallSprite().size(); j++)
			{
				if(collision.isCollided(Map, j, itr)) collision.collisionSet();
			}
			if(collision.isCollided(itr, Hero)) collision.collisionSet();

			for (list<Monsters*>::iterator Previtr = Monster.begin(); Previtr != itr && collision.checkIfAlreadyCollided() == false; Previtr++)
			{
				if(collision.isCollided(itr, Previtr)) collision.collisionSet();
			}

			for (list<Chests>::iterator chestItr = Chest.begin(); chestItr != Chest.end(); chestItr++)
			{
				if(collision.isCollided(chestItr, itr)) collision.collisionSet();
			}
	
			if (collision.checkIfAlreadyCollided())
			{
				temp_x = rand() % ((globalWidth / boardSquareSize) - 1) + 1;
				temp_x *= boardSquareSize;

				temp_y = rand() % ((globalHeight / boardSquareSize) - 1) + 1;
				temp_y *= boardSquareSize;

				(*itr)->setPosition(temp_x, temp_y);
			}
		} while (collision.checkIfAlreadyCollided());
	}
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


bool App::higherMap()
{
	vector<string> current_map = map.get_map();

	if (current_map[heroCoord[1]][heroCoord[0]] == stairsSign) return true;
	else false;
}
*/