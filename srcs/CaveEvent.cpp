/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The CaveEvent class simulates what happens on the Cave Space. The CaveEvent class
takes the monsters that are on the Cave Space and has the heroes fight them at random with a high
probability that they will fight. The Hero is rewarded with a random amount of gold that is above
1500G for beating the monsters. 
**************************************************************************************************/
#include "CaveEvent.hpp"
#include <iostream>

CaveEvent::CaveEvent(Team *heroes, Space *cave){
	setMenu(new Menu());
	setHeroes(heroes);
	setSpace(cave);
	if(areMonstersAlive()){
		int chance = rand() %10;
		if(chance < 7){
			encounter();
			if(getHeroes()->getIsTeamAlive()){
				int reward = rand() % 2000 + 1500;	
				std::cout << "The monsters drop some gold." << std:: endl;
				getHeroes()->setGold(getHeroes()->getGold() + reward);
				std::cout << "You have " << getHeroes()->getGold() << "G." << std::endl << std::endl;
			}
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