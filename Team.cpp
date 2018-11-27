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
