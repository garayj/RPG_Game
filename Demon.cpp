/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation file for the Demon Class. The Demon Class is a character within
the Heroes Quest Game. Demon has an Armor rating of 5, Max Health of 10, attacks with 3d3 and
defend with 3d3. 
*************************************************************************************************/
#include "Demon.hpp"
#include <iostream>

Demon::Demon(){
	setIsAlive(true);
	setArmor(8);
	setMaxHealth(30);
	setSpeed(6);
	setHealth(getMaxHealth());
	setNumberDefDie(4);
	setNumberAttDie(6);
	setDefDieSides(4);
	setAttDieSides(6);
	setCharacterType(MONSTER);
	setCharacterClass(DEMON);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

Demon::~Demon(){

}

