#include "DefensePotion.hpp"
#include <iostream>

DefensePotion::DefensePotion(){
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