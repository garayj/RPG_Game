/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The DungeonEvent Class extends the Event class and contains the events that occur on
a Dungeon Space. On a Dungeon Space, things are the most dangerous. If there are monsters alive, you
have to fight them. The chance of encounter is 100%. The enemies are also pretty strong. There are
keys here as reward though.
**************************************************************************************************/
#include "DungeonEvent.hpp"
#include "Key.hpp"
#include <iostream>

DungeonEvent::DungeonEvent(Team *heroes, Space *dungeon){

	setMenu(new Menu());
	setHeroes(heroes);
	setSpace(dungeon);
	if(areMonstersAlive()){
			encounter();
			if(getHeroes()->getIsTeamAlive()){

				int gold = rand() % 2000;
				std::cout << "You found a key that the king wanted!" << std::endl << std:: endl;
				Item *key = new Key();
				heroes->getInventory()->push_back(key);
				std::cout << "You also found some gold on the ground." << std::endl;
				std::cout << "You got " << gold << "G."<< std::endl;
				getHeroes()->setGold(getHeroes()->getGold() + gold);
				std::cout << "You now have " << getHeroes()->getGold() << "G." << std::endl;

			}

	}
	else{
		std::cout << "Looks like you already beat these guys to a pulp. Lets get out of this creepy place.\n\n";
	}
	delete getMenu();
}

