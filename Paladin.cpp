/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Implementation file for the Paladin Class. The Paladin Class is a character within
the unknown Fantasy Game. Paladin has an Armor rating of 10, Max Health of 30, attacks with 3d6 and
defend with 3d6. The Paladin class is the only class that does not have a special ability.
*************************************************************************************************/
#include "Paladin.hpp"
#include <iostream>

Paladin::Paladin(){
	setIsAlive(true);
	setArmor(10);
	setMaxHealth(30);
	setSpeed(4);
	setHealth(getMaxHealth());
	setNumberDefDie(3);
	setNumberAttDie(3);
	setDefDieSides(6);
	setAttDieSides(6);
	setCharacterType(HERO);
	setCharacterClass(PALADIN);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

Paladin::~Paladin(){

}