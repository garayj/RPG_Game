/**************************************************************************************************
** Author: Jose Garay
** Date: 11/26/2018
** Description: Interface for the Team class. The Team class simulates a team of characters that 
may be either monsters or heroes. Teams have a location, size, Characters, an inventory, and a 
boolean data member to check whether the Team is alive or not.
**************************************************************************************************/
#include "Team.hpp"
#include <iostream>
using std::cout;
using std::endl;

Team::Team(int size){
	setIsTeamAlive(true);
	setTeamSize(size);
	setLocation(nullptr);
	characters = new Character*[getTeamSize()];
}

Team::~Team(){
	if(getCharacters() != nullptr){
		for(int n = 0; n < getTeamSize(); n++){
			if(getCharacters()[n] != nullptr){
				delete getCharacters()[n];
			}
		}
		delete [] getCharacters();
	}	
}

bool Team::teamAliveStatus(){
	for(int n = 0; n < getTeamSize(); n++){
		if(getCharacters()[n]->getIsAlive()){
			return true;
		}
	}
	setIsTeamAlive(false);
	return false;
}

void Team::printCharacters(){
	int place = 1; 
	for(int n = 0; n < getTeamSize(); n++){
		if(getCharacters()[n]->getIsAlive()){
			// cout << place << ". " << getCharacters()[n]->getName() << " the "<< getCharacters()[n]->getCharacterClassString() << endl;
			place++;
		}
	}


}
