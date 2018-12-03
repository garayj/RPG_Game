/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the ForestTroll Class. The ForestTroll Class is a character within
the Heroes Quest Game. ForestTroll has an Armor rating of 6, Max Health of 20, attacks with 3d4 and
defend with 3d5. 
*************************************************************************************************/
#include "ForestTroll.hpp"
#include <iostream>

ForestTroll::ForestTroll(){
	setIsAlive(true);
	setArmor(6);
	setMaxHealth(20);
	setSpeed(2);
	setHealth(getMaxHealth());
	setNumberDefDie(3);
	setNumberAttDie(3);
	setDefDieSides(5);
	setAttDieSides(4);
	setCharacterType(MONSTER);
	setCharacterClass(FOREST_TROLL);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

ForestTroll::~ForestTroll(){

}