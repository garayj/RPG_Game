#include "PhoenixDown.hpp"
#include "BlackMage.hpp"
#include "WhiteMage.hpp"
#include <iostream>

PhoenixDown::PhoenixDown(){
	setItemType(POTION);
	setEffect(0);
	setItemName("Phoenix Down");
	setDescription("A feather of a blessed seagull.\n");
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