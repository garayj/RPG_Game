/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The VillageEvent Class inherits from the the Event class and contains the events 
that occur on a Village Space. On a Village Space, things are hustle and bustle. The user is able 
to look at the inventory, go sleep at the near by inn, move on, buy items at the local shop, or end 
the game. No monster battles can occur here.
**************************************************************************************************/
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
#include <vector>



VillageEvent::VillageEvent(Team *heroes){
	int itemSelection;
	setMenu(new Menu());
	//Vector holding all the prices of the items.
	std::vector<int>prices = {1000,400,2000,500,1000,2000,1500,100,1000,1000};

	getMenu()->addMenuLine(MAIN_MENU);
	getMenu()->printMenu();

	int selection = getMenu()->checkInputInt(ERROR_MENU, 0, 4);
	//Go into the inventory and either equip weapons and armor or use a potion.
	while(selection == 1 || selection == 4){
		switch(selection){
			//The user chooses to look at the inventory.
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
			//The user chooses to buy something from the shop.
			case 4:
				getMenu()->clear();
				getMenu()->addMenuLine(MERCHANT);
				getMenu()->printMenu();
				//Select an option.
				itemSelection = getMenu()->checkInputInt(ERROR,0 ,10);

				if(itemSelection){
					if(!heroes->isInventoryFull()){
						if(heroes->getGold() >= prices.at(itemSelection - 1)){
							heroes->getInventory()->push_back(createItem(itemSelection, heroes));
						}
						else{
							std::cout << "You don't have enough money!\n\n";
						}
					}
					else{
						getMenu()->clear();
						getMenu()->addMenuLine(INVENTORY_FULL);
						getMenu()->printMenu();
					}
				}
				break;
		}
		//Reprompt the main menu if either merchant or look at inventory is chosen.
		getMenu()->clear();
		getMenu()->addMenuLine(MAIN_MENU);	
		getMenu()->printMenu();
		selection = getMenu()->checkInputInt(ERROR_MENU, 0, 4);
	}
	//Quit the Game
	if(selection == 0){
		heroes->setIsTeamAlive(false);	
		getMenu()->clear();
		getMenu()->addMenuLine(QUIT);
		getMenu()->printMenu();
	}
	//Sleep at the inn for the night.
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

Item* VillageEvent::createItem(int input, Team *heroes){
	Item *output;
	int swordPrice = 1000,
		shieldPrice = 400,
		bWandPrice = 2000,
		hWandPrice = 500,
		hammerPrice = 1000,
		daggerPrice = 2000,
		xbowPrice = 1500,
		hPotPrice = 100,
		pDownPrice = 1000,
		dPotPrice = 1000;

	switch(input){
		case 1:
			output = new GreaterSword();
			std::cout << "You bought a Greater Sword!\n\n";
			heroes->setGold(heroes->getGold() - swordPrice);
			break;
		case 2:
			output = new MagicShield();
			std::cout << "You bought a Magic Shield!\n\n";
			heroes->setGold(heroes->getGold() - shieldPrice);
			break;
		case 3:
			output = new BattleWand();
			std::cout << "You bought a Battle Wand!\n\n";
			heroes->setGold(heroes->getGold() - bWandPrice);
			break;
		case 4:
			output = new HealingWand();
			std::cout << "You bought a Healing Wand!\n\n";
			heroes->setGold(heroes->getGold() - hWandPrice);
			break;
		case 5:
			output = new GreatHammer();
			std::cout << "You bought a Great Hammer!\n\n";
			heroes->setGold(heroes->getGold() - hammerPrice);
			break;
		case 6:
			output = new SharpDagger();
			std::cout << "You bought a Sharp Dagger!\n\n";
			heroes->setGold(heroes->getGold() - daggerPrice);
			break;
		case 7:
			output = new Crossbow();
			std::cout << "You bought a Crossbow!\n\n";
			heroes->setGold(heroes->getGold() - xbowPrice);
			break;
		case 8:
			output = new HealthPotion();
			std::cout << "You bought a Healing Potion!\n\n";
			heroes->setGold(heroes->getGold() - hPotPrice);
			break;
		case 9:
			output = new PhoenixDown();
			std::cout << "You bought a Phoenix Down!\n\n";
			heroes->setGold(heroes->getGold() - pDownPrice);
			break;
		case 10:
			output = new DefensePotion();
			std::cout << "You bought a Defense Potion!\n\n";
				heroes->setGold(heroes->getGold() - dPotPrice);
			break;
	}
	return output;
}