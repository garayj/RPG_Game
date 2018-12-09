/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the MudGoblin Class. The MudGoblin Class is a character within
the Heroes Quest Game. MudGoblin has an Armor rating of 0, Max Health of 10, attacks with 3d3 and
defend with 2d6. 
*************************************************************************************************/
#include "MudGoblin.hpp"
#include <iostream>

MudGoblin::MudGoblin(){
	setIsAlive(true);
	setArmor(0);
	setMaxHealth(10);
	setSpeed(8);
	setHealth(getMaxHealth());
	setNumberDefDie(2);
	setNumberAttDie(3);
	setDefDieSides(6);
	setAttDieSides(3);
	setCharacterType(MONSTER);
	setCharacterClass(MUD_GOBLIN);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

MudGoblin::~MudGoblin(){

}