#include "CaveEvent.hpp"
#include <iostream>

CaveEvent::CaveEvent(Team *heroes, Space *cave){
	setMenu(new Menu());
	setHeroes(heroes);
	setSpace(cave);
	if(areMonstersAlive()){
		int chance = rand() %10;
		if(chance < 6){
			encounter();
		}
		else{
			std::cout << "You stay quiet and move quickly. You escape without confrontation.\n\n";
		}
	}
	else{
		std::cout << "Looks like you already beat these guys to a pulp. Lets get out of this creepy place.\n\n";
	}
	delete getMenu();
}