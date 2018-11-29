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
#include <iostream>

GrassEvent::GrassEvent(){}

GrassEvent::GrassEvent(Team *heroes){
	menu = new Menu();
	monsters = nullptr;



	getMenu()->addMenuLine(MAIN_MENU);
	getMenu()->printMenu();
	int selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
	while(selection == 1){
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
		std::cout << hero->getCharacters()[n]->getIsAlive() << std::endl;
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