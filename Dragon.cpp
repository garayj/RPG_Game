/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation file for the Dragon Class. The Dragon Class is a character within
the Heroes Quest Game. Dragon has an Armor rating of 15, Max Health of 50, attacks with 5d5 and
defend with 4d6. 
*************************************************************************************************/
#include "Dragon.hpp"
#include <iostream>

Dragon::Dragon(){
	setIsAlive(true);
	setArmor(15);
	setMaxHealth(50);
	setSpeed(4);
	setHealth(getMaxHealth());
	setNumberDefDie(4);
	setNumberAttDie(6);
	setDefDieSides(6);
	setAttDieSides(8);
	setCharacterType(MONSTER);
	setCharacterClass(DRAGON);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

Dragon::~Dragon(){

}