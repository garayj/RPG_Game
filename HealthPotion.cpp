/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the HealthPotion class. The HealthPotion class is an Item that 
inherits from the Potion class. A HealthPotion can be used to heal for 5 HP.
**************************************************************************************************/
#include "HealthPotion.hpp"
#include <iostream>

HealthPotion::HealthPotion(){
	setIsBirdFeather(false);
	setItemType(POTION);
	setEffect(5);
	setItemName("Health Potion");
	setDescription("A health potion instantly restores 5 HP to a character.\nTastes like chicken!\n");
}

HealthPotion::~HealthPotion(){
}

void HealthPotion::usePotion(Character *hero){
	if(hero->getHealth() + getEffect() > hero->getMaxHealth()){
		std::cout << hero->getName() << " the " << hero->getCharacterClassString() << " gained " <<
			hero->getMaxHealth() - hero->getHealth() << " HP." << std::endl;
		hero->setHealth(hero->getMaxHealth());
	}
	else{
		hero->setHealth(hero->getHealth() + 5 );
	}
}