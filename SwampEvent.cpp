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

