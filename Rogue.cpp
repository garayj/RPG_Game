/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Implementation file for the Rogue Class. The Rogue Class is a character within
the unknown Fantasy Game. Rogue has an Armor rating of 2, Max Health of 12, attacks with 9d3 and
defend with 1d5. 
*************************************************************************************************/
#include "Rogue.hpp"
#include <iostream>

Rogue::Rogue(){
	setArmor(2);
	setMaxHealth(12);
	setHealth(getMaxHealth());
	setNumberDefDie(1);
	setNumberAttDie(9);
	setDefDieSides(5);
	setAttDieSides(3);
	setCharacterType(HERO);
	setCharacterClass(ROGUE);
	setSpeed(10);
	setIsAlive(true);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

Rogue::~Rogue(){

}