/**************************************************************************************************
** Author: Jose Garay
** Date: 11/26/2018
** Description: Interface for the Team class. The Team class simulates a team of characters that 
may be either monsters or heroes. Teams have a location, size, Characters, an inventory, and a 
boolean data member to check whether the Team is alive or not.
**************************************************************************************************/
#include "Team.hpp"
#include "Menu.hpp"
#include "Potion.hpp"
#include "Equipment.hpp"
#include <iostream>
#include "WhiteMage.hpp"
#include "BlackMage.hpp"
#include <iomanip>
using std::setw;
using std::cout;
using std::endl;

Team::Team(int size){
	setInventorySize(10);
	setIsTeamAlive(true);
	setTeamSize(size);
	setLocation(nullptr);
	setGold(1000);

	setInventory(new vector<Item*>());

	characters = new Character*[getTeamSize()];
	// inventory = new Item*[getInventory()->size()];

	//Set every space in the inventory to null for an empty inventory.
	// for(int n = 0; n < getInventory()->size(); n++){
	// 	getInventory()->push_back(nullptr);
	// }
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
	while(!getInventory()->empty()){
		delete getInventory()->at(getInventory()->size() - 1);
		getInventory()->pop_back();
	}
	delete getInventory();

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
		cout << place << ". " << getCharacters()[n]->getName() << " the "<< getCharacters()[n]->getCharacterClassString() << endl;
		place++;
	}
	cout << "\n";
}

void Team::teamStats(){
		cout << "#  ";
		cout << setw(10);
		cout << "Name";
		cout << "|";
		cout << setw(15);
		cout << "Class";
		cout << "|";
		cout << setw(6);
		cout << "Armor";
		cout << "|";
		cout << setw(4);
		cout << "HP";
		cout << "|";
		cout << setw(6);
		cout << "Max HP";
		cout << "|";
		cout << setw(4);
		cout << "Mana";
		cout << "|";
		cout << setw(9);
		cout << "Max Mana";
		cout << endl;
		cout << "----------------------------------------------------------------"<< endl;
	for(int n = 1; n <= getTeamSize(); n++){
		cout << n << ": ";
		cout << setw(10);
		cout << getCharacters()[n -1]->getName();
		cout << "|";
		cout << setw(15);
		cout << getCharacters()[n -1]->getCharacterClassString();
		cout << "|";
		cout << setw(6);
		cout << getCharacters()[n -1]->getArmor();
		cout << "|";
		cout << setw(4);
		cout << getCharacters()[n -1]->getHealth();
		cout << "|";
		cout << setw(6);
		cout << getCharacters()[n -1]->getMaxHealth();
		cout << "|";
		if(getCharacters()[n -1]->getCharacterClass() == BLACK_MAGE || getCharacters()[n -1]->getCharacterClass() == WHITE_MAGE){
			switch(getCharacters()[n -1]->getCharacterClass()){
				case BLACK_MAGE:
					cout << setw(4);
					cout << dynamic_cast<BlackMage*>(getCharacters()[n -1])->getMana();
					cout << "|";
					cout << setw(9);
					cout << dynamic_cast<BlackMage*>(getCharacters()[n -1])->getMaxMana();
					break;
				case WHITE_MAGE:
					cout << setw(4);
					cout << dynamic_cast<WhiteMage*>(getCharacters()[n -1])->getMana();
					cout << "|";
					cout << setw(9);
					cout << dynamic_cast<WhiteMage*>(getCharacters()[n -1])->getMaxMana();
					break;
			}
		}
		else{
			cout << setw(4);
			cout << "N/A";
			cout << "|";
			cout << setw(9);
			cout << "N/A";
		}
		cout << endl;

	}
}

void Team::addItemToInventory(Item *newItem){
	getInventory()->push_back(newItem);
}



void Team::removeItemFromInventory(int n){
	delete getInventory()->at(n);
	getInventory()->erase(getInventory()->begin() + n);
}

void Team::printInventory(){
	int count = 1;
	for(int n = 0; n < getInventory()->size();n++){
		if(getInventory()->at(n) != nullptr){
			cout << count << ": " << getInventory()->at(n)->getItemName() << endl;
			count++;
		}
	}
	cout << "\n\n";
}


void Team::inventoryMenu(int itemIndex){
	Menu menu;
	int characterIndex;
	if(getInventory()->at(itemIndex - 1)->getItemType() == POTION){
		Menu menu;
		cout << "Select the item you would like to use or select 0 to go back.\n";
		printCharacters();				

		characterIndex = menu.checkInputInt("Oops please select an item in the inventory\n", 1, getTeamSize());

		dynamic_cast<Potion*>(getInventory()->at(itemIndex - 1))->usePotion(getCharacters()[characterIndex - 1]);
		delete getInventory()->at(itemIndex - 1);

		getInventory()->erase(getInventory()->begin() + itemIndex - 1);

	}
	else{

		cout << "Who would you like to hold this?\n";
		printCharacters();				
		characterIndex = menu.checkInputInt("Ooops! Please select a hero in the menu\n", 1, getTeamSize());

		//Check if the first slot is taken.
		if(getCharacters()[characterIndex -1]->getSlot1() == nullptr){
			if(getCharacters()[characterIndex - 1]->getCharacterClass() == dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1))->getClassType()){
				getCharacters()[characterIndex - 1]->setSlot1(dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1)));
				cout << getCharacters()[characterIndex - 1]->getName() << " is now holding " << getCharacters()[characterIndex - 1]->getSlot1()->getItemName() << " in slot 1." << std::endl;
				getInventory()->erase(getInventory()->begin() + itemIndex - 1);
			}
			else{
				cout << "This is not meant for this hero!" << endl;
			}
		}


		//Check if the second slot is taken.
		else if(getCharacters()[characterIndex - 1]->getSlot2() == nullptr){
			getCharacters()[characterIndex - 1]->setSlot2(dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1)));
			cout << getCharacters()[characterIndex - 1]->getName() << " is now holding " << getCharacters()[characterIndex - 1]->getSlot2()->getItemName() << " in slot 2." << std::endl;
			getInventory()->erase(getInventory()->begin() + itemIndex - 1);
		}
	}
}


