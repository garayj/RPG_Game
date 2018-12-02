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
	setGold(3000);
	setInventory(new vector<Item*>());

	characters = new Character*[getTeamSize()];
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
		cout << "|";
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
	if(getInventory()->size() < getInventorySize()){
		getInventory()->push_back(newItem);
	}
	else{
		cout << "The inventory is full!" << endl;
	}
}

bool Team::isInventoryFull(){
	if(getInventory()->size() == getInventorySize()){
		return true;
	}
	else{
		return false;
	}
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
	int input;
	cout << "This is the item index: "<<itemIndex << endl;
	cout << "Would you like to use this Item or throw it away?\n1: Use/Equip it\n0: Remove it from inventory.\n";
	input = menu.checkInputInt("Error!\n1: Use/Equip it\n0: Remove it from inventory.\n", 0, 1);

	if(input == 1){
		useItem(itemIndex);
	}
	else{
		removeItemFromInventory(itemIndex - 1);
	}


}

void Team::useItem(int itemIndex){

	//Check if the item the user wants to use is a potion.
	if(getInventory()->at(itemIndex - 1)->getItemType() == POTION){
		usePotion(itemIndex);
	}
	//If the item is not a Potion type then it must be an Equipment type.
	else{
		equip(itemIndex);
	}

}

void Team::equip(int itemIndex){
	Menu menu;
	int characterIndex;
	//Check if the item is a Weapon type.
	if(dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1))->getType() == WEAPON){
		cout << "Who would you like to hold this?\n";
		printCharacters();

		//Validate user input.
		characterIndex = menu.checkInputInt("Ooops! Please select a hero in the menu\n", 1, getTeamSize());

		//Check if the Equipment is made for the Character.
		if(getCharacters()[characterIndex - 1]->getCharacterClass() == dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1))->getClassType()){

			//Check if the first slot is taken.
			if(getCharacters()[characterIndex -1]->getSlot1() == nullptr){

					//Have the first slot point to the weapon, display a message, and remove it from the inventory.
					getCharacters()[characterIndex - 1]->setSlot1(dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1)));
					cout << getCharacters()[characterIndex - 1]->getName() << " is now holding " << getCharacters()[characterIndex - 1]->getSlot1()->getItemName() << " in slot 1." << std::endl;
					getInventory()->erase(getInventory()->begin() + itemIndex - 1);
					
			}
			//Check if the second slot is taken.
			else if(getCharacters()[characterIndex - 1]->getSlot2() == nullptr){

				//Have the second slot point to the weapon, display a message, and remove it from the inventory.
				getCharacters()[characterIndex - 1]->setSlot2(dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1)));
				cout << getCharacters()[characterIndex - 1]->getName() << " is now holding " << getCharacters()[characterIndex - 1]->getSlot2()->getItemName() << " in slot 2." << std::endl;
				getInventory()->erase(getInventory()->begin() + itemIndex - 1);
			}
			else{
				cout << "This hero is already holding two pieces of Equipment.\n" << endl;
			}
		}
		else{
			cout << "This is not meant for this hero!" << endl;
		}
	}
	//If the equipment is a shield
	else{
		//Check if the first slot is taken.
		if(getCharacters()[characterIndex -1]->getSlot1() == nullptr){

				//Have the first slot point to the weapon, display a message, and remove it from the inventory.
				getCharacters()[characterIndex - 1]->setSlot1(dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1)));
				cout << getCharacters()[characterIndex - 1]->getName() << " is now holding " << getCharacters()[characterIndex - 1]->getSlot1()->getItemName() << " in slot 1." << std::endl;
				getInventory()->erase(getInventory()->begin() + itemIndex - 1);
				
		}
		//Check if the second slot is taken.
		else if(getCharacters()[characterIndex - 1]->getSlot2() == nullptr){

			//Have the second slot point to the weapon, display a message, and remove it from the inventory.
			getCharacters()[characterIndex - 1]->setSlot2(dynamic_cast<Equipment*>(getInventory()->at(itemIndex - 1)));
			cout << getCharacters()[characterIndex - 1]->getName() << " is now holding " << getCharacters()[characterIndex - 1]->getSlot2()->getItemName() << " in slot 2." << std::endl;
			getInventory()->erase(getInventory()->begin() + itemIndex - 1);
		}
		else{
			cout << "This hero is already holding two pieces of Equipment.\n" << endl;
		}
	}

}

void Team::usePotion(int itemIndex){
	Menu menu;
	cout << "Select the hero you would like to use the item on.\n";
	printCharacters();				

	//Validate the user is entering a valid character to use the potion type on.
	int characterIndex = menu.checkInputInt("Oops please select a hero in your party.\n", 1, getTeamSize());

	//Use the potion, free the memory and remove it from the inventory.
	dynamic_cast<Potion*>(getInventory()->at(itemIndex - 1))->usePotion(getCharacters()[characterIndex - 1]);
	delete getInventory()->at(itemIndex - 1);
	getInventory()->erase(getInventory()->begin() + itemIndex - 1);

}
