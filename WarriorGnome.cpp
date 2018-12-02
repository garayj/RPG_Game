/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Implementation file for the WarriorGnome Class. The WarriorGnome Class is a character within
the unknown Fantasy Game. WarriorGnome has an Armor rating of 7, Max Health of 20, attacks with 4d4 and
defend with 5d5. 
*************************************************************************************************/
#include "WarriorGnome.hpp"
#include <iostream>

WarriorGnome::WarriorGnome(){
	setArmor(7);
	setMaxHealth(20);
	setHealth(getMaxHealth());
	setNumberDefDie(5);
	setNumberAttDie(4);
	setDefDieSides(5);
	setAttDieSides(4);
	setCharacterType(HERO);
	setCharacterClass(WARRIOR_GNOME);
	setSpeed(5);
	setIsAlive(true);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

WarriorGnome::~WarriorGnome(){

}