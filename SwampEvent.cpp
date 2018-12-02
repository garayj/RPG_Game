/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The SwampEvent Class inherits from the Event class and contains the events that 
occur on a Swamp Space. On a Swamp Space, there are Zombie and Mud Goblin types. Either a fight 
will happen or you run into no trouble or you manage to get out without a problem.
**************************************************************************************************/
#include "SwampEvent.hpp"
#include "Zombie.hpp"
#include "quickSort.hpp"
#include "MudGoblin.hpp"
#include <iostream>
#include <vector>

using std::vector;

SwampEvent::SwampEvent(Team *heroes, Space *swamp){
	if(areMonstersAlive(swamp)){
		int chance = rand() %10;
		std::cout << "Is the chance changing: " << chance << std::endl;
		if(chance < 6){
			encounter(heroes, swamp);
		}
		else{
			std::cout << "You stay quiet and move quickly. You escape without confrontation.\n\n";
		}
	}
	else{
		std::cout << "Looks like you already beat these guys to a pulp. Lets get out of this creepy place.\n\n";
	}

}

void SwampEvent::encounter(Team *heroes, Space *swamp){
	vector<Character*>allFighters;
	for(int n = 0; n < heroes->getTeamSize(); n++){
		if(heroes->getCharacters()[n]->getIsAlive()){
			allFighters.push_back(heroes->getCharacters()[n]);
		}
	}
	for(int n = 0; n < swamp->getMonsterCount(); n++){
		if(swamp->getMonsters()[n] != nullptr){
			allFighters.push_back(swamp->getMonsters()[n]);
		}
	}
	for(int n = 1; n <= allFighters.size(); n++){
		std::cout << n << ": " << allFighters.at(n - 1)->getCharacterClassString() << " has a speed of " << allFighters.at(n - 1)->getSpeed() << std::endl;
	}
	quickSort(&allFighters, 0, allFighters.size() - 1);
	for(int n = 1; n <= allFighters.size(); n++){
		std::cout << n << ": " << allFighters.at(n - 1)->getCharacterClassString() << " has a speed of " << allFighters.at(n - 1)->getSpeed() << std::endl;
	}
}

bool SwampEvent::areMonstersAlive(Space* swamp){
	for(int n = 0; n < swamp->getMonsterCount(); n++){
		if(swamp->getMonsters()[n] != nullptr){
			return true;
		}
	}
	return false;
}
void SwampEvent::monsterDies(Character* monster){
	delete monster;
	monster = nullptr;
}

void SwampEvent::heroDies(Character *hero){
	hero->setHealth(0);
	hero->setIsAlive(false);
}