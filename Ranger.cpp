/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the Ranger Class. The Ranger Class is a character within
the unknown Fantasy Game. Ranger has an Armor rating of 3, Max Health of 15, attacks with 4d4 and
defend with 2d6. 
*************************************************************************************************/
#include "Ranger.hpp"
#include <iostream>

Ranger::Ranger(){
	setIsAlive(true);
	setSpeed(8);
	setArmor(3);
	setMaxHealth(15);
	setHealth(getMaxHealth());
	setNumberDefDie(2);
	setNumberAttDie(4);
	setDefDieSides(6);
	setAttDieSides(4);
	setCharacterType(HERO);
	setCharacterClass(RANGER);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

Ranger::~Ranger(){

}