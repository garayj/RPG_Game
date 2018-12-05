/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the DefensePotion class. The DefensePotion is an Item is Potion
that you can use to permanantly increase your defense rating. The DefensePotion inherits from the 
Potion class.
**************************************************************************************************/
#include "DefensePotion.hpp"
#include <iostream>

DefensePotion::DefensePotion(){
	setIsBirdFeather(false);
	setItemType(POTION);
	setEffect(5);
	setItemName("Defense Potion");
	setDescription("It tastes like a tank.\n");
}

DefensePotion::~DefensePotion(){
}

void DefensePotion::usePotion(Character *hero){
	hero->setArmor(hero->getArmor() + getEffect());
}