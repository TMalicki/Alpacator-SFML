#include "Hero.h"
#include "Barbarian.h"
#include "Knight.h"
#include "Monk.h"
#include "Assassin.h"
#include "Mage.h"

void Hero::DrawCharacter(int heigh, int width)
{
	if (this != nullptr)
	{
		string prof = this->getProfession();
		if (prof == "Barbarian") THero.loadFromFile("images/characters/alpacaBarbarian.png");
		else if (prof == "Knight") THero.loadFromFile("images/characters/alpacaKnight.png");
		else if (prof == "Monk") THero.loadFromFile("images/characters/alpacaMonk.png");
		else if (prof == "Assassin") THero.loadFromFile("images/characters/alpacaAssassin.png");
		else if (prof == "Mage") THero.loadFromFile("images/characters/alpacaMage.png");
	}
	SHero.setTexture(THero);
}

void Hero::MoveCharacter(int change_x, int change_y)
{
	SHero.move(change_x, change_y);	
}

Hero* Hero::ChooseProfession(sf::RenderWindow& window, sf::Event& event, sf::Texture& tKnight, sf::Sprite& SKnight, sf::Texture& tBarbarian, sf::Sprite& SBarbarian, sf::Texture& tMage, sf::Sprite& SMage, 
	sf::Texture& tMonk, sf::Sprite& SMonk, sf::Texture& tAssassin, sf::Sprite& SAssassin)
{
	Hero* hero = nullptr;

	int minValS = 1000;
	int maxValS = 0;
	int minValD = 1000;
	int maxValD = 0;
	int minValH = 1000;
	int maxValH = 0;
	int minValAgil = 1000;
	int maxValAgil = 0;
	int minValStam = 1000;
	int maxValStam = 0;

	int starsCount = 0;

	if (minValS == 1000 && maxValS == 0)
	{
		Hero* temp = nullptr;

		for (int i = 0; i < 5; i++)
		{
			if (i == 0) temp = new Assassin("TOM");
			else if (i == 1) temp = new Barbarian("TOM");
			else if (i == 2) temp = new Knight("TOM");
			else if (i == 3) temp = new Mage("TOM");
			else if (i == 4) temp = new Monk("TOM");

			if (minValS > temp->getStrength()) minValS = temp->getStrength();
			if (maxValS < temp->getStrength()) maxValS = temp->getStrength();
			if (minValD > temp->getDefence()) minValD = temp->getDefence();
			if (maxValD < temp->getDefence()) maxValD = temp->getDefence();
			if (minValH > temp->getHp()) minValH = temp->getHp();
			if (maxValH < temp->getHp()) maxValH = temp->getHp();
			if (minValAgil > temp->getAgillity()) minValAgil = temp->getAgillity();
			if (maxValAgil < temp->getAgillity()) maxValAgil = temp->getAgillity();
			if (minValStam > temp->getStam()) minValStam = temp->getStam();
			if (maxValStam < temp->getStam()) maxValStam = temp->getStam();

			delete temp;
			temp = nullptr;
		}
	}

	sf::Texture TbackGround;
	TbackGround.loadFromFile("images/chooseHero.png");
	sf::Texture TbackgroundStats;
	TbackgroundStats.loadFromFile("images/backgroundStats.png");
	sf::Texture TAlpacaStatUnchecked;
	TAlpacaStatUnchecked.loadFromFile("images/alpacaStatUnchecked.png");
	sf::Texture TAlpacaStatChecked;
	TAlpacaStatChecked.loadFromFile("images/alpacaStatChecked.png");

	sf::Sprite backGround;
	backGround.setTexture(TbackGround);
	sf::Sprite backGroundStats;
	backGroundStats.setTexture(TbackgroundStats);
	backGroundStats.setPosition(0, 600);
	sf::Sprite SAlpacaStatUnchecked;
	SAlpacaStatUnchecked.setTexture(TAlpacaStatUnchecked);
	SAlpacaStatUnchecked.setScale(0.6, 0.6);
	sf::Sprite SAlpacaStatChecked;
	SAlpacaStatChecked.setTexture(TAlpacaStatChecked);
	SAlpacaStatChecked.setScale(0.6, 0.6);

	sf::Font font;
	font.loadFromFile("fonts/QuiteMagical.TTF");

	sf::Text profession;
	profession.setFont(font);
	profession.setCharacterSize(40);

	int mid_x = (800 / 2) - ((50*3)/2);
	int mid_y = (600 / 2) - ((50*3)/2) + 100;

	int d_x = 0;
	int d_y = 0;

	int mX = 300; int mY = 100;

	int borderDown = mid_x - (2 * mX);
	int borderUp = mid_x + (2 * mX);

	tKnight.loadFromFile("images/characters/alpacaKnight.png");
	tBarbarian.loadFromFile("images/characters/alpacaBarbarian.png");
	tMage.loadFromFile("images/characters/alpacaMage.png");
	tMonk.loadFromFile("images/characters/alpacaMonk.png");
	tAssassin.loadFromFile("images/characters/alpacaAssassin.png");

	SKnight.setTexture(tKnight);
	SBarbarian.setTexture(tBarbarian);
	SMage.setTexture(tMage);
	SMonk.setTexture(tMonk);
	SAssassin.setTexture(tAssassin);

	SKnight.setScale(3, 3);
	SBarbarian.setScale(3, 3);
	SMage.setScale(3, 3);
	SMonk.setScale(3, 3);
	SAssassin.setScale(3, 3);

	SMonk.setPosition(mid_x + 2 * mX, mid_y - mY);
	SKnight.setPosition(mid_x + mX, mid_y - mY);
	SMage.setPosition(mid_x, mid_y);
	SBarbarian.setPosition(mid_x - mX, mid_y - mY);
	SAssassin.setPosition(mid_x - 2 * mX, mid_y - mY);

	bool choose = 0;
	bool changeCharacter = true;

	while (!choose)
	{
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				choose = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				d_x = -mX;
		
				int tempPosX;

				tempPosX = SMonk.getPosition().x;
				if (tempPosX + d_x == mid_x) SMonk.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x >= borderDown) SMonk.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x < borderDown) SMonk.setPosition(mid_x + 2 * mX, mid_y - mY);

				tempPosX = SKnight.getPosition().x;
				if (tempPosX + d_x == mid_x) SKnight.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x >= borderDown) SKnight.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x < borderDown) SKnight.setPosition(mid_x + 2 * mX, mid_y - mY);

				tempPosX = SMage.getPosition().x;
				if (tempPosX + d_x == mid_x) SMage.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x >= borderDown) SMage.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x < borderDown) SMage.setPosition(mid_x + 2 * mX, mid_y - mY);

				tempPosX = SBarbarian.getPosition().x;
				if (tempPosX + d_x == mid_x) SBarbarian.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x >= borderDown) SBarbarian.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x < borderDown) SBarbarian.setPosition(mid_x + 2 * mX, mid_y - mY);

				tempPosX = SAssassin.getPosition().x;
				if (tempPosX + d_x == mid_x) SAssassin.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x >= borderDown) SAssassin.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x < borderDown) SAssassin.setPosition(mid_x + 2 * mX, mid_y - mY);

				changeCharacter = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				d_x = mX;

				int tempPosX;

				tempPosX = SMonk.getPosition().x;
				if (tempPosX + d_x == mid_x) SMonk.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x <= borderUp) SMonk.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x > borderUp) SMonk.setPosition(mid_x - 2 * mX, mid_y - mY);

				tempPosX = SKnight.getPosition().x;
				if (tempPosX + d_x == mid_x) SKnight.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x <= borderUp) SKnight.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x > borderUp) SKnight.setPosition(mid_x - 2 * mX, mid_y - mY);

				tempPosX = SMage.getPosition().x;
				if (tempPosX + d_x == mid_x) SMage.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x <= borderUp) SMage.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x > borderUp) SMage.setPosition(mid_x - 2 * mX, mid_y - mY);

				tempPosX = SBarbarian.getPosition().x;
				if (tempPosX + d_x == mid_x) SBarbarian.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x <= borderUp) SBarbarian.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x > borderUp) SBarbarian.setPosition(mid_x - 2 * mX, mid_y - mY);

				tempPosX = SAssassin.getPosition().x;
				if (tempPosX + d_x == mid_x) SAssassin.setPosition(mid_x, mid_y);
				else if (tempPosX + d_x <= borderUp) SAssassin.setPosition(tempPosX + d_x, mid_y - mY);
				else if (tempPosX + d_x > borderUp) SAssassin.setPosition(mid_x - 2 * mX, mid_y - mY);

				changeCharacter = true;
			}
		}

		d_x = 0;
		d_y = 0;

		if (SAssassin.getPosition().x == mid_x && changeCharacter == true)
		{
			if (hero != nullptr)
			{
				delete hero;
				hero = nullptr;
			}
			hero = new Assassin("TOM");
			profession.setString("ASSASSIN");
		}
		else if (SBarbarian.getPosition().x == mid_x && changeCharacter == true)
		{
			if (hero != nullptr)
			{
				delete hero;
				hero = nullptr;
			}
			hero = new Barbarian("TOM");
			profession.setString("BARBARIAN");
		}
		else if (SMage.getPosition().x == mid_x && changeCharacter == true)
		{
			if (hero != nullptr)
			{
				delete hero;
				hero = nullptr;
			}
			hero = new Mage("TOM");
			profession.setString("MAGE");
		}
		else if (SKnight.getPosition().x == mid_x && changeCharacter == true)
		{
			if (hero != nullptr)
			{
				delete hero;
				hero = nullptr;
			}
			hero = new Knight("TOM");
			profession.setString("KNIGHT");
		}
		else if (SMonk.getPosition().x == mid_x && changeCharacter == true)
		{
			if (hero != nullptr)
			{
				delete hero;
				hero = nullptr;
			}
			hero = new Monk("TOM");
			profession.setString("MONK");
		}

		changeCharacter = false;

		sf::FloatRect ProftextRect = profession.getLocalBounds();

		profession.setOrigin(ProftextRect.left + ProftextRect.width / 2.0f, ProftextRect.top + ProftextRect.height / 2.0f);
		profession.setPosition(400, mid_y - 100);

		window.clear();

		window.draw(backGround);
		window.draw(backGroundStats);
		window.draw(SMonk);
		window.draw(SKnight);
		window.draw(SMage);
		window.draw(SBarbarian);
		window.draw(SAssassin);
		window.draw(profession);

		/// atk ///
		for (int i = 0; i < 6; i++) {
			SAlpacaStatUnchecked.setPosition(80 + 25 * i, 655);
			window.draw(SAlpacaStatUnchecked);
		}

		if(hero != nullptr) starsCount = ((hero->getStrength() - minValS) * (6 - 1) / (maxValS - minValS)) + 1;

		for (int i = 0; i < starsCount; i++) {
			SAlpacaStatChecked.setPosition(80 + 25 * i, 655);
			window.draw(SAlpacaStatChecked);
		}
		/// def ///
		for (int i = 0; i < 6; i++) {
			SAlpacaStatUnchecked.setPosition(340 + 25 * i, 655);
			window.draw(SAlpacaStatUnchecked);
		}

		if (hero != nullptr) starsCount = ((hero->getDefence() - minValD) * (6 - 1) / (maxValD - minValD)) + 1;

		for (int i = 0; i < starsCount; i++) {
			SAlpacaStatChecked.setPosition(340 + 25 * i, 655);
			window.draw(SAlpacaStatChecked);
		}
		/// hp ///
		for (int i = 0; i < 6; i++) {
			SAlpacaStatUnchecked.setPosition(80 + 25 * i, 620);
			window.draw(SAlpacaStatUnchecked);
		}

		if (hero != nullptr) starsCount = ((hero->getHp() - minValH) * (6 - 1) / (maxValH - minValH)) + 1;

		for (int i = 0; i < starsCount; i++) {
			SAlpacaStatChecked.setPosition(80 + 25 * i, 620);
			window.draw(SAlpacaStatChecked);
		}
		/// agility ///
		for (int i = 0; i < 6; i++) {
			SAlpacaStatUnchecked.setPosition(340 + 25 * i, 620);
			window.draw(SAlpacaStatUnchecked);
		}

		if (hero != nullptr) starsCount = ((hero->getAgillity() - minValAgil) * (6 - 1) / (maxValAgil - minValAgil)) + 1;

		for (int i = 0; i < starsCount; i++) {
			SAlpacaStatChecked.setPosition(340 + 25 * i, 620);
			window.draw(SAlpacaStatChecked);
		}
		/// stamina ///
		for (int i = 0; i < 6; i++) {
			SAlpacaStatUnchecked.setPosition(600 + 25 * i, 620);
			window.draw(SAlpacaStatUnchecked);
		}

		if (hero != nullptr) starsCount = ((hero->getStam() - minValStam) * (6 - 1) / (maxValStam - minValStam)) + 1;

		for (int i = 0; i < starsCount; i++) {
			SAlpacaStatChecked.setPosition(600 + 25 * i, 620);
			window.draw(SAlpacaStatChecked);
		}

		window.display();
	}
	return hero;
}
void Hero::getFromChest(vector<Items*> item)
{
	for (int i = 0; i < item.size(); i++)
	{
		this->items.push_back(item[i]);
		cout << item[i]->getName() << endl;
	}
}
vector<Items*> Hero::openBackpack()
{
	return this->items;
}
sf::Text Hero::printStats()
{
		font.loadFromFile("fonts/QuiteMagical.ttf");
		StatInfo.setFont(font);
		StatInfo.setCharacterSize(20);

		//this->getDefence();
		//StatInfo.setString(this.getName());
		StatInfo.setString(to_string(this->getStrength()));
		StatInfo.setOrigin(0, 10);
		StatInfo.setPosition(120, 600);
	
	return StatInfo;
}
/*
void Hero::HeroChooseWheel(sf::Sprite& sprite, int dx, int midX, int midY)
{
	int dy = 0;
	if((sprite.getPosition().x + dx >= midX) && (sprite.getPosition().x <= midX - 600)) dy = 50;
}
*/