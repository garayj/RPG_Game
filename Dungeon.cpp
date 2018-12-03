/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation for the Dungeon class. The Dungeon space inherits from the Space 
class. The Dungeon represents a Dungeon on the map. Dungons have the keys that the king is looking 
for but there are also dangerous monsters that live here. Be careful! There are dragons and demons
about!
**************************************************************************************************/
#include "Dungeon.hpp"
#include "Demon.hpp"
#include "Dragon.hpp"

Dungeon::Dungeon(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(DUNGEON);
	setMonsterCount(3);
	setMonsters(new Character*[getMonsterCount()]);
	for(int n = 0; n < getMonsterCount(); n++){
		if(rand() % 2 == 0){
			getMonsters()[n] = new Demon();
		}
		else{
			getMonsters()[n] = new Dragon();
		}
	}	
}

Dungeon::~Dungeon(){
	for(int n = 0; n < getMonsterCount(); n++){
		if(getMonsters()[n] != nullptr){
			delete getMonsters()[n];
		}
	}
	delete []getMonsters();
}
	
