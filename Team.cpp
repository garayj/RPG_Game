#include "Team.hpp"

Team::Team(){
	setTeamSize(3);
	setLocation(nullptr);
	setHeroes(nullptr);
}

Team::~Team(){
	if(getHeroes() != nullptr){
		for(int n = 0; n < getTeamSize(); n++){
			if(getHeroes()[n] != nullptr){
				delete getHeroes()[n];
			}
		}
		delete getHeroes();
	}	
}
