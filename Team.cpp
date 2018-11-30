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
	setInventorySize(10);
	setIsTeamAlive(true);
	setTeamSize(size);
	setLocation(nullptr);

	characters = new Character*[getTeamSize()];
	inventory = new Item*[getInventorySize()];

	//Set every space in the inventory to null for an empty inventory.
	for(int n = 0; n < getInventorySize(); n++){
		inventory[n] = nullptr;
	}
}

Team::~Team(){
	//Delete all the Characters in the Team.
	if(getCharacters() != nullptr){
		for(int n = 0; n < getTeamSize(); n++){
			if(getCharacters()[n] != nullptr){
				delete getCharacters()[n];
			}
		}
		delete [] getCharacters();
	}	
	//Delete anything left in the inventory.
	for(int n = 0; n < getInventorySize(); n++){
		if(getInventory()[n] != nullptr){
			delete getInventory()[n];

		}
	}
	delete [] getInventory();

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
	//
	for(int n = 0; n < getTeamSize(); n++){
		cout << place << ". " << getCharacters()[n]->getName() << " the "<< getCharacters()[n]->getCharacterClassString() << endl;
		place++;
	}
	cout << "\n";
}

void Team::addItemToInventory(Item *newItem){
	bool itemNotPlaced = true;
	int n = 0;
	while(itemNotPlaced && n < getInventorySize()){
		if(getInventory()[n] == nullptr){
			getInventory()[n] = newItem;
			itemNotPlaced = false;
		}
		n++;
	}
}

bool Team::isInventoryEmpty(){
	for(int n = 0; n < getInventorySize();n++){
		if(getInventory()[n] != nullptr){
			return false;
		}
	}
	return true;
}

void Team::removeItemFromInventory(int n){
	delete getInventory()[n];
	getInventory()[n] = nullptr;
}



