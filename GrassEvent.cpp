/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The GrassEvent Class extends the Event class and contains the events that occur on
a Grass Space. On a Grass Space, things are simple and easy. The user is able to look at the
inventory, camp, move on, or end the game. No monster battles can occur here.
**************************************************************************************************/
#include "GrassEvent.hpp"
#include "Menu.hpp"
#include "grassStrings.hpp"
#include "GreaterSword.hpp"
#include "Equipment.hpp"
#include "Potion.hpp"
#include "HealthPotion.hpp"
#include <iostream>

using std::cout;

GrassEvent::GrassEvent(){}

GrassEvent::GrassEvent(Team *heroes){
	monsters = nullptr;
	setMenu(new Menu());
	//This is for testing.
	// Equipment *sword1 = new GreaterSword();
	// Equipment *sword2 = new GreaterSword();
	// Equipment *sword3 = new GreaterSword();
	// heroes->getInventory()->push_back(sword1);
	// heroes->getInventory()->push_back(sword2);
	// heroes->getInventory()->push_back(sword3);

	getMenu()->addMenuLine(MAIN_MENU);
	getMenu()->printMenu();

	int selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
	//Go into the inventory and either equip weapons and armor or use a potion.
	while(selection == 1){

		getMenu()->clear();
		getMenu()->addMenuLine(INVENTORY);
		getMenu()->printMenu();
		//Print out all the things in the inventory.
		heroes->printInventory();

		getMenu()->clear();
		getMenu()->addMenuLine(USE_ITEM);
		getMenu()->printMenu();

		selection = getMenu()->checkInputInt(ERROR + USE_ITEM, 0, heroes->getInventory()->size());

		//If the user decides to equip a weapon or armor or use a potion the item is checked here.
		if(selection > 0){
			//check inventory
			heroes->inventoryMenu(selection);
		}
		getMenu()->clear();
		getMenu()->addMenuLine(MAIN_MENU);	
		getMenu()->printMenu();
		selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
	}
	//Quit the Game
	if(selection == 0){
		heroes->setIsTeamAlive(false);	
		getMenu()->clear();
		getMenu()->addMenuLine(QUIT);
		getMenu()->printMenu();
	}
	//Rest for the night.
	else if(selection == 2){
		getMenu()->clear();
		getMenu()->addMenuLine(REST);
		getMenu()->printMenu();
		rest(heroes);
	}
	//Mosey on.
	else{
		getMenu()->clear();
		getMenu()->addMenuLine(CONTINUE);
		getMenu()->printMenu();
	}
	delete menu;
}

void GrassEvent::rest(Team *hero){
	int heal = 5;

	//I adapted the White Mages healParty method for this.
	for(int n = 0; n < hero->getTeamSize(); n++){
		if(hero->getCharacters()[n]->getIsAlive()){
			if(heal + hero->getCharacters()[n]->getHealth() > hero->getCharacters()[n]->getMaxHealth()){
				hero->getCharacters()[n]->setHealth(hero->getCharacters()[n]->getMaxHealth());
			}
			else{
				hero->getCharacters()[n]->setHealth(heal + hero->getCharacters()[n]->getHealth());
			}
		}
	}
}

GrassEvent::~GrassEvent(){
}