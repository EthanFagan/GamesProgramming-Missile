// Author Ethan Fagan
// Date started: 20/09/2018
//-------------------------------------------------------------
// A missile game where the player selects a warhead type and attempts to hit
//-------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <string.h>

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << std::endl;
	}

}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;

struct Missile {
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;

	}
};

int main()
{
	srand(time(nullptr));
	//----------------------------------
	float timer = 0;
	//----------------------------------
	int warheadType = 0;
	//----------------------------------
	Missile enemySlayer;
	Enemy enemy;
	//----------------------------------
	int launchCode1 = rand() % 8999 + 1000;
	//----------------------------------
	enemy.coordinates.x = rand() % 50 + 1;
	enemy.coordinates.y = rand() % 50 + 1;
	//----------------------------------
	int launchCoordinate = 0;
	//----------------------------------
	int playersInputtedCode = 0;


	std::cout << "Select a warhead type" << std::endl << "1 = EXPLOSIVE" << std::endl << "2 = NUCLEAR" << std::endl;
	std::cin >> warheadType;
    
	//-----------------------------------------------------------------------------------
	if (warheadType == 1)
	{
		enemySlayer.payload = EXPLOSIVE;
		std::cout << "payload set to EXPLOSIVE" << std::endl;
	}
	if (warheadType == 2)
	{
		enemySlayer.payload = NUCLEAR;
		std::cout << "payload set to NUCLEAR" << std::endl;
    }
	else
	{
		std::cout << " \\ you did not choose an appropriate type, warhead has been set to explosive // " << std::endl;
		enemySlayer.payload = EXPLOSIVE;
	}
	//------------------------------------------------------------------------------------

	std::cout << "The enemys current location is between [" << enemy.coordinates.x << "," << enemy.coordinates.y << "]" << std::endl;


	std::cout << "Now enter the launch co-ordinates" << std::endl << "enter the X Value" << std::endl;
	std::cin >> launchCoordinate;
	enemySlayer.target.coordinates.x = launchCoordinate;
	launchCoordinate = 0;

	std::cout << "Now enter the Y Value" << std::endl;
	std::cin >> launchCoordinate;
	enemySlayer.target.coordinates.y = launchCoordinate;
	launchCoordinate = 0;

	//------------------------------------------------------------------------------------
	while (playersInputtedCode != launchCode1)
	{
		std::cout << "Co-ordinates locked in" << std::endl << "To fire payload, enter the launch code [" << launchCode1 << "]" << std::endl;
		std::cin >> playersInputtedCode;
	}
	//------------------------------------------------------------------------------------
	
	std::cout << "MISSILE LAUNCHED," << std::endl;

	if (enemySlayer.target.coordinates.x == enemy.coordinates.x && enemySlayer.target.coordinates.y == enemy.coordinates.y)
	{
		std::cout << "JACKPOT" << std::endl << "target obliterated" << std::endl << "Press F to pay respects" << std::endl;
	}
	else
	{
		std::cout << "Shot missed, disappointing" << std::endl;
	}


	std::system("pause");
}
