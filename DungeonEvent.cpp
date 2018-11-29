#include "DungeonEvent.hpp"
#include <iostream>

DungeonEvent::DungeonEvent(Team *heroes){
	int chanceOfEncounter = rand() % 10 + 1;
	if(chanceOfEncounter > 7){
		//fight
		std::cout << "A fight should happen here." << std::endl;
	}
	else{
		//The dungeon should have some good loot. Key or something.
		std::cout << "Looks like there was nothing in the dungeon!" << std::endl;
		std::cout << "What a disappointment!\n\n";
	}
}