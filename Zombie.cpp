/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Implementation file for the Zombie Class. The Zombie Class is a character within
the unknown Fantasy Game. Zombie has an Armor rating of 0, Max Health of 15, attacks with 3d6 and
defend with 1d6. 
*************************************************************************************************/
#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
	setIsAlive(true);
	setArmor(0);
	setMaxHealth(15);
	setSpeed(3);
	setHealth(getMaxHealth());
	setNumberDefDie(1);
	setNumberAttDie(3);
	setDefDieSides(6);
	setAttDieSides(6);
	setCharacterType(MONSTER);
	setCharacterClass(ZOMBIE);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

Zombie::~Zombie(){

}