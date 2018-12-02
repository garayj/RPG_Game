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