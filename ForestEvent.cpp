/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The ForestEvent Class extends the Event class and contains the events that occur on
a Forest Space. On a Forest Space, things are not very dangerous. If there are monsters alive, the 
user has a low chance of fighting them but the reward is high if you are lucky enough to find them 
and beat them.
**************************************************************************************************/
#include <iostream>
#include "ForestEvent.hpp"

ForestEvent::ForestEvent(Team *heroes, Space *forest){

	setMenu(new Menu());
	setHeroes(heroes);
	setSpace(forest);
	if(areMonstersAlive()){
		int chance = rand() %10;
		if(chance < 2){
			encounter();
			if(getHeroes()->getIsTeamAlive()){
				int reward = 4000;
				std::cout << "These guys had a ton of loot. You pick up 4000G" << std:: endl;
				getHeroes()->setGold(getHeroes()->getGold() + reward);
				std::cout << "You have " << getHeroes()->getGold() << "G." << std::endl << std::endl;
			}
		}
		else{
			std::cout << "The forest is quiet today. You walk through the thick of it with no confrontations.\n\n";
		}
	}
	else{
		std::cout << "Looks like you already beat these guys to a pulp.\n\n";
	}
	delete getMenu();
}