/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation for the Swamp Class. The Swamp class represents a Swamp space on the 
map. The Swamp class represents a swampy area that's spooky and scary. Zombies and Mud Goblins live
here. Don't get stuck here!
**************************************************************************************************/
#include "Swamp.hpp"
#include "MudGoblin.hpp"
#include "Zombie.hpp"

Swamp::Swamp(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(SWAMP);
	setMonsterCount(3);
	setMonsters(new Character*[getMonsterCount()]);
	//Make three monsters for the Swamp space.
	for(int n = 0; n < getMonsterCount(); n++){
		if(rand() % 2 == 0){
			getMonsters()[n] = new MudGoblin();
		}
		else{
			getMonsters()[n] = new Zombie();
		}
	}	
}

Swamp::~Swamp(){
	for(int n = 0; n < getMonsterCount(); n++){
		if(getMonsters()[n] != nullptr){
			delete getMonsters()[n];
		}
	}
	delete []getMonsters();
}