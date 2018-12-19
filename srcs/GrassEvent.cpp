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


GrassEvent::GrassEvent(Team *heroes){
	setHeroes(heroes);
	setMenu(new Menu());

	getMenu()->printMenu(MAIN_MENU);

	int selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
	//Go into the inventory and either equip weapons and armor or use a potion.
	bool noActionMade = true;
	while(selection == 1){
		noActionMade = true;
		while(noActionMade){
			noActionMade = inventoryAction();
		}
		getMenu()->printMenu(MAIN_MENU);
		selection = getMenu()->checkInputInt(ERROR_MENU, 0, 3);
	}
	//Quit the Game
	if(selection == 0){
		getHeroes()->setIsTeamAlive(false);	
		getMenu()->printMenu(QUIT);
	}
	//Rest for the night.
	else if(selection == 2){
		getMenu()->printMenu(REST);
		rest();
	}
	//Mosey on.
	else{
		getMenu()->printMenu(CONTINUE);
	}
	delete menu;
}

void GrassEvent::rest(){
	int heal = 5;

	//I adapted the White Mages healParty method for this.
	for(int n = 0; n < getHeroes()->getTeamSize(); n++){
		if(getHeroes()->getCharacters()[n]->getIsAlive()){
			if(heal + getHeroes()->getCharacters()[n]->getHealth() > getHeroes()->getCharacters()[n]->getMaxHealth()){
				getHeroes()->getCharacters()[n]->setHealth(getHeroes()->getCharacters()[n]->getMaxHealth());
			}
			else{
				getHeroes()->getCharacters()[n]->setHealth(heal + getHeroes()->getCharacters()[n]->getHealth());
			}
		}
	}
}

GrassEvent::~GrassEvent(){
}