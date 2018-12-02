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
	setHeroes(heroes);
	int itemSelection;
	setMenu(new Menu());

	//Vector holding all the prices of the items.
	std::vector<int>prices = {1000,400,2000,500,1000,2000,1500,100,1000,1000};

	getMenu()->addMenuLine(MAIN_MENU);
	getMenu()->printMenu();

	int selection = getMenu()->checkInputInt(ERROR_MENU, 0, 4);
	bool noActionMade = true;
	//Go into the inventory and either equip weapons and armor or use a potion.
	while(selection == 1 || selection == 4){
		switch(selection){
			//The user chooses to look at the inventory.
			case 1:
				noActionMade = true;
				while(noActionMade){
					noActionMade = inventoryAction();
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
					if(!getHeroes()->isInventoryFull()){
						if(getHeroes()->getGold() >= prices.at(itemSelection - 1)){
							getHeroes()->getInventory()->push_back(createItem(itemSelection));
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
		rest();
	}
	//Mosey on.
	else{
		getMenu()->clear();
		getMenu()->addMenuLine(CONTINUE);
		getMenu()->printMenu();
	}
	delete menu;
}
void VillageEvent::rest(){

	//I adapted the White Mages healParty method for this.
	for(int n = 0; n < getHeroes()->getTeamSize(); n++){
		if(getHeroes()->getCharacters()[n]->getIsAlive()){
			switch(getHeroes()->getCharacters()[n]->getCharacterClass()){
				case WHITE_MAGE:
					dynamic_cast<WhiteMage*>(getHeroes()->getCharacters()[n])->setMana(dynamic_cast<WhiteMage*>(getHeroes()->getCharacters()[n])->getMaxMana());
					getHeroes()->getCharacters()[n]->setHealth(getHeroes()->getCharacters()[n]->getMaxHealth());
					break;
				case BLACK_MAGE:
					dynamic_cast<BlackMage*>(getHeroes()->getCharacters()[n])->setMana(dynamic_cast<BlackMage*>(getHeroes()->getCharacters()[n])->getMaxMana());
					getHeroes()->getCharacters()[n]->setHealth(getHeroes()->getCharacters()[n]->getMaxHealth());
					break;
				case PALADIN:
				case ROGUE:
				case RANGER:
				case WARRIOR_GNOME:
					getHeroes()->getCharacters()[n]->setHealth(getHeroes()->getCharacters()[n]->getMaxHealth());
					break;

			}
		}
	}
}

Item* VillageEvent::createItem(int input){
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
			getHeroes()->setGold(getHeroes()->getGold() - swordPrice);
			break;
		case 2:
			output = new MagicShield();
			std::cout << "You bought a Magic Shield!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - shieldPrice);
			break;
		case 3:
			output = new BattleWand();
			std::cout << "You bought a Battle Wand!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - bWandPrice);
			break;
		case 4:
			output = new HealingWand();
			std::cout << "You bought a Healing Wand!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - hWandPrice);
			break;
		case 5:
			output = new GreatHammer();
			std::cout << "You bought a Great Hammer!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - hammerPrice);
			break;
		case 6:
			output = new SharpDagger();
			std::cout << "You bought a Sharp Dagger!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - daggerPrice);
			break;
		case 7:
			output = new Crossbow();
			std::cout << "You bought a Crossbow!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - xbowPrice);
			break;
		case 8:
			output = new HealthPotion();
			std::cout << "You bought a Healing Potion!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - hPotPrice);
			break;
		case 9:
			output = new PhoenixDown();
			std::cout << "You bought a Phoenix Down!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - pDownPrice);
			break;
		case 10:
			output = new DefensePotion();
			std::cout << "You bought a Defense Potion!\n\n";
			getHeroes()->setGold(getHeroes()->getGold() - dPotPrice);
			break;
	}
	return output;
}