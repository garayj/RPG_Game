#include "Game.hpp"
#include <iostream>
#include <string>
#include "Character.hpp"
#include "Team.hpp"
#include "Vampire.hpp"
#include "Map.hpp"
#include <ctime> 
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
void move(Team*);

int main(int argc, char const *argv[])
{
	Game game;
	game.run();
	return 0;

	
	Team *heroTeam;
	heroTeam = new Team();

	srand(time(NULL));
	Map map;
	map.printMap();
	cout << endl;

	map.setHeroes(heroTeam);
	heroTeam->setLocation(map.getBoard()[0][0]);
	map.printMap();
	for(int n = 0; n < 3; n++){
		move(heroTeam);
		map.printMap();
	}

	delete heroTeam;





	return 0;
}

