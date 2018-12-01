#include "VillageEvent.hpp"
#include "villageStrings.hpp"
#include "WhiteMage.hpp"
#include "BlackMage.hpp"					
#include <iostream>

VillageEvent::VillageEvent(Team *heroes){
	monsters = nullptr;
	setMenu(new Menu());

	getMenu()->addMenuLine(MAIN_MENU);
	getMenu()->printMenu();

	int selection = getMenu()->checkInputInt(ERROR_MENU, 0, 4);
	//Go into the inventory and either equip weapons and armor or use a potion.
	while(selection == 1 || selection == 4){
		switch(selection){
			case 1:
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
					getMenu()->clear();
					getMenu()->addMenuLine(MAIN_MENU);	
					getMenu()->printMenu();
					selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
				}
				break;
			case 4:
				getMenu()->clear();
				getMenu()->addMenuLine(MERCHANT);
				getMenu()->printMenu();

				break;
		}
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
void VillageEvent::rest(Team *hero){

	//I adapted the White Mages healParty method for this.
	for(int n = 0; n < hero->getTeamSize(); n++){
		if(hero->getCharacters()[n]->getIsAlive()){
			switch(hero->getCharacters()[n]->getCharacterClass()){
				case WHITE_MAGE:
					dynamic_cast<WhiteMage*>(hero->getCharacters()[n])->setMana(dynamic_cast<WhiteMage*>(hero->getCharacters()[n])->getMaxMana());
					hero->getCharacters()[n]->setHealth(hero->getCharacters()[n]->getMaxHealth());
					break;
				case BLACK_MAGE:
					dynamic_cast<BlackMage*>(hero->getCharacters()[n])->setMana(dynamic_cast<BlackMage*>(hero->getCharacters()[n])->getMaxMana());
					hero->getCharacters()[n]->setHealth(hero->getCharacters()[n]->getMaxHealth());
					break;
				case PALADIN:
				case ROGUE:
				case RANGER:
				case WARRIOR_GNOME:
					hero->getCharacters()[n]->setHealth(hero->getCharacters()[n]->getMaxHealth());
					break;

			}
		}
	}
}