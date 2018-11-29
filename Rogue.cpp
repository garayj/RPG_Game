/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Implementation file for the Rogue Class. The Rogue Class is a character within
the unknown Fantasy Game. Rogue has an Armor rating of 2, Max Health of 12, attacks with 4d6 and
defend with 1d5. The Rogue class is the only class that does not have a special ability.
*************************************************************************************************/
#include "Rogue.hpp"
#include <iostream>

Rogue::Rogue(){
	setIsAlive(true);
	setArmor(2);
	setMaxHealth(12);
	setHealth(getMaxHealth());
	setNumberDefDie(1);
	setNumberAttDie(4);
	setDefDieSides(5);
	setAttDieSides(6);
	setCharacterType(HERO);
	setCharacterClass(ROGUE);
	setSpeed(10);
}

Rogue::~Rogue(){

}