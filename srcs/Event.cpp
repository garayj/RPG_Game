/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The Event Class is an abstract class that will be used to contain all the events
that will occur on each space on the board.
**************************************************************************************************/
#include "Event.hpp"
#include "inventoryStrings.hpp"

Event::Event(){}
Event::~Event(){}


bool Event::inventoryAction(){
	bool noActionMade;	
	int selection;
	getMenu()->clear();
	getMenu()->addMenuLine(INVENTORY);
	getMenu()->printMenu();
	//Print out all the things in the inventory.
	getHeroes()->printInventory();

	getMenu()->clear();
	getMenu()->addMenuLine(USE_ITEM);
	getMenu()->printMenu();

	selection = getMenu()->checkInputInt(ERROR + USE_ITEM, 0, getHeroes()->getInventory()->size());

	//If the user decides to equip a weapon or armor or use a potion the item is checked here.
	if(selection == 0){
		noActionMade = false;
	}
	else if(getHeroes()->getInventory()->at(selection - 1)->getItemType() == KEY){
		getMenu()->clear();
		getMenu()->addMenuLine(KEY_WARNING);
		getMenu()->printMenu();
		noActionMade = false;
	}
	else{
		//check inventory
		noActionMade = getHeroes()->inventoryMenu(selection);
	}

	return noActionMade;
}
