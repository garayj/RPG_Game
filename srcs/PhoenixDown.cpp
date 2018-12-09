/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: The PhoenixDown Class inherits from the Potion class. If a hero is killed from 
battle, another hero may revive him using a Phoenix Down.
**************************************************************************************************/
#include "PhoenixDown.hpp"
#include "BlackMage.hpp"
#include "WhiteMage.hpp"
#include <iostream>

PhoenixDown::PhoenixDown(){
	setItemType(POTION);
	setEffect(0);
	setItemName("Phoenix Down");
	setDescription("A feather of a blessed seagull.\n");
	setIsBirdFeather(true);
}

PhoenixDown::~PhoenixDown(){
}

void PhoenixDown::usePotion(Character *hero){
	hero->setHealth(hero->getMaxHealth());
	hero->setIsAlive(true);
	if(hero->getCharacterClass() == BLACK_MAGE){
		dynamic_cast<BlackMage*>(hero)->setMana(dynamic_cast<BlackMage*>(hero)->getMaxMana());
	}
	else if(hero->getCharacterClass() == WHITE_MAGE){
		dynamic_cast<WhiteMage*>(hero)->setMana(dynamic_cast<WhiteMage*>(hero)->getMaxMana());
	}
}