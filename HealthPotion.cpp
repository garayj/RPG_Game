#include "HealthPotion.hpp"
#include <iostream>

HealthPotion::HealthPotion(){
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