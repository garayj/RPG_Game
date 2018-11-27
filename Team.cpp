#include "Team.hpp"
#include <iostream>
using std::cout;
using std::endl;

Team::Team(){
	setTeamSize(3);
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

void Team::printCharacters(){
	int place = 1; 
	for(int n = 0; n < getTeamSize(); n++){
		if(getCharacters()[n]->getIsAlive()){
			cout << place << ". " << getCharacters()[n]->getName() << " the "<< getCharacters()[n]->getCharacterClassString() << endl;
			place++;
		}
	}


}
