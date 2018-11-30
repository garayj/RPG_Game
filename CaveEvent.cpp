#include "CaveEvent.hpp"
#include <iostream>

CaveEvent::CaveEvent(Team *heroes){
	int chanceOfEncounter = rand() % 10 + 1;
	if(chanceOfEncounter < 7){
		//fight
		std::cout << "A fight should happen here." << std::endl;
	}
	else{

		std::cout << "Looks like there was nothing in the cave!" << std::endl;
		std::cout << "What a disappointment!\n\n";
	}
}