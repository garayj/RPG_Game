/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation file for the Bandits Class. The Bandits Class is a character within
the Heroes Quest Game. Bandits has an Armor rating of 7, Max Health of 12, attacks with 2d6 and
defend with 1d6. 
*************************************************************************************************/
#include "Bandits.hpp"
#include <iostream>

Bandits::Bandits(){
	setIsAlive(true);
	setArmor(7);
	setMaxHealth(12);
	setSpeed(7);
	setHealth(getMaxHealth());
	setNumberDefDie(1);
	setNumberAttDie(2);
	setDefDieSides(6);
	setAttDieSides(6);
	setCharacterType(MONSTER);
	setCharacterClass(BANDITS);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

Bandits::~Bandits(){

}