/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation for the Forest Class. The Forest class represents a Forest space on the 
map. The Forest is mostly serene. Bandits and Forest Trolls are about but they are sparce. A mostly
safe area.
**************************************************************************************************/
#include "Forest.hpp"
#include "Bandits.hpp"
#include "ForestTroll.hpp"

Forest::Forest(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(FOREST); 
	setMonsterCount(3);
	setMonsters(new Character*[getMonsterCount()]);
	//Make three monsters for the Forest space.
	for(int n = 0; n < getMonsterCount(); n++){
		if(rand() % 2 == 0){
			getMonsters()[n] = new Bandits();
		}
		else{
			getMonsters()[n] = new ForestTroll();
		}
	}	
}

Forest::~Forest(){
	for(int n = 0; n < getMonsterCount(); n++){
		if(getMonsters()[n] != nullptr){
			delete getMonsters()[n];
		}
	}
	delete []getMonsters();
}