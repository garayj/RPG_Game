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
#include <iostream>

GrassEvent::GrassEvent(){}

GrassEvent::GrassEvent(Team *heroes){
	menu = new Menu();
	monsters = nullptr;

	Equipment *sword;

	getMenu()->addMenuLine(MAIN_MENU);
	getMenu()->printMenu();

	int selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
	while(selection == 1){
		std::cout << "Would you like to equip a sword?" << std::endl;
		selection = getMenu()->checkInputInt(ERROR_MENU, 0, 1);
		if(selection){
			sword = new GreaterSword();
			std::cout << "Which character?\n\n";
			for(int n = 0; n < heroes->getTeamSize(); n++){
				std:: cout  << n +1 << ": " << heroes->getCharacters()[n]->getCharacterClassString() << std::endl;
			}
			selection = menu->checkInputInt("Select a character", 1, heroes->getTeamSize());
			if(heroes->getCharacters()[selection - 1]->getCharacterClass() == PALADIN){
				if(heroes->getCharacters()[selection - 1]->getSlot1() == nullptr ){
					heroes->getCharacters()[selection - 1]->setSlot1(sword);
				}
				else if(heroes->getCharacters()[selection - 1]->getSlot2() == nullptr){
					heroes->getCharacters()[selection - 1]->setSlot2(sword);
				}
				else{
					std::cout << "There are no more slots left!" << std::endl;
					delete sword;
				}
			}

			else{
				delete sword;
				std::cout << "That character cannot use that!\n\n";
			}
		}


		//check inventory
		getMenu()->printMenu();
		selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
	}

	if(selection == 0){
		heroes->setIsTeamAlive(false);	
		getMenu()->clear();
		getMenu()->addMenuLine(QUIT);
		getMenu()->printMenu();
	}
	else if(selection == 2){
		getMenu()->clear();
		getMenu()->addMenuLine(REST);
		getMenu()->printMenu();
		rest(heroes);
	}
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