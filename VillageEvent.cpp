#include "VillageEvent.hpp"
#include "villageStrings.hpp"
#include "WhiteMage.hpp"
#include "BlackMage.hpp"

#include "DefensePotion.hpp"
#include "HealthPotion.hpp"
#include "PhoenixDown.hpp"

#include "GreaterSword.hpp"
#include "SharpDagger.hpp"
#include "GreatHammer.hpp"
#include "BattleWand.hpp"
#include "HealingWand.hpp"
#include "MagicShield.hpp"
#include "Crossbow.hpp"

#include <iostream>

VillageEvent::VillageEvent(Team *heroes){
	int itemSelection;
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
				}
				break;
			case 4:
				getMenu()->clear();
				getMenu()->addMenuLine(MERCHANT);
				getMenu()->printMenu();
				itemSelection =getMenu()->checkInputInt(ERROR,0 ,10);
				if(itemSelection){
					heroes->getInventory()->push_back(createItem(itemSelection));

				}

				break;
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

Item* VillageEvent::createItem(int input){
	Item *output;
	switch(input){
		case 1:
			output = new GreaterSword();
			break;
		case 2:
			output = new MagicShield();
			break;
		case 3:
			output = new BattleWand();
			break;
		case 4:
			output = new HealingWand();
			break;
		case 5:
			output = new GreatHammer();
			break;
		case 6:
			output = new SharpDagger();
			break;
		case 7:
			output = new Crossbow();
			break;
		case 8:
			output = new HealthPotion();
			break;
		case 9:
			output = new PhoenixDown();
			break;
		case 10:
			output = new DefensePotion();
			break;
	}
}