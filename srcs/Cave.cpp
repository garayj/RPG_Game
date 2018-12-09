/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation for the Cave class. The Cave space inherits from the Space class. The 
Cave represents a Cave on the map. Caves are dangerous places. There are powerful cave trolls and
giant spiders about. Not a fun place to be. Stay safe!
**************************************************************************************************/
#include "Cave.hpp"
#include "CaveTroll.hpp"
#include "GiantSpider.hpp"

Cave::Cave(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(CAVE);
	setMonsterCount(3);
	setMonsters(new Character*[getMonsterCount()]);

	//Make enemies at spaces at random between CaveTrolls and Giant Spiders.
	for(int n = 0; n < getMonsterCount(); n++){
		if(rand() % 2 == 0){
			getMonsters()[n] = new CaveTroll();
		}
		else{
			getMonsters()[n] = new GiantSpider();
		}
	}	

}


Cave::~Cave(){
	for(int n = 0; n < getMonsterCount(); n++){
		if(getMonsters()[n] != nullptr){
			delete getMonsters()[n];
		}
	}
	delete []getMonsters();
}