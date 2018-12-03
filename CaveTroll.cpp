/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation file for the CaveTroll Class. The CaveTroll Class is a character within
the Heroes Quest Game. CaveTroll has an Armor rating of 8, Max Health of 25, attacks with 3d6 and
defend with 2d5. 
*************************************************************************************************/
#include "CaveTroll.hpp"
#include <iostream>

CaveTroll::CaveTroll(){
	setIsAlive(true);
	setArmor(8);
	setMaxHealth(25);
	setSpeed(1);
	setHealth(getMaxHealth());
	setNumberDefDie(2);
	setNumberAttDie(3);
	setDefDieSides(5);
	setAttDieSides(6);
	setCharacterType(MONSTER);
	setCharacterClass(CAVE_TROLL);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

CaveTroll::~CaveTroll(){

}