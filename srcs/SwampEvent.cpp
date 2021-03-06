/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The SwampEvent Class extends the Event class and contains the events that occur on
a Swamp Space. On a Swamp Space, things are dangerous. If there are monsters alive, the user has a
small chance to sneak on by or walk into trouble. If the user has already defeated the monsters,
the user walks into no more trouble. Zombies and mud goblins live here.
**************************************************************************************************/
#include "SwampEvent.hpp"
#include <iostream>

using std::cout;
using std::endl;

SwampEvent::SwampEvent(Team *heroes, Space *swamp){

	setMenu(new Menu());
	setHeroes(heroes);
	setSpace(swamp);
	if(areMonstersAlive()){
		int chance = rand() %10;
		if(chance < 5){
			encounter();
			if(getHeroes()->getIsTeamAlive()){
				int reward = rand() % 1000 + 1;	
				std::cout << "The monsters drop some gold." << std:: endl;
				getHeroes()->setGold(getHeroes()->getGold() + reward);
				std::cout << "You have " << getHeroes()->getGold() << "G." << std::endl << std::endl;
			}
		}
		else{
			std::cout << "You stay quiet and move quickly. You escape without confrontation. It's creepy being in the swamp!\n\n";
		}
	}
	else{
		std::cout << "Looks like you already beat these guys to a pulp. Lets get out of this creepy place.\n\n";
	}
	delete getMenu();
}

