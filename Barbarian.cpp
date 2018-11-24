/**************************************************************************************************
** Author: Jose Garay
** Date: 11/3/2018
** Description: Implementation file for the Barbarian Class. The Barbarian Class is a character within
the Fantasy Combat Game. Barbarian has an Armor rating of 0, Strength of 12, attack with 2d6 and
defend with 2d6. The Barbarian class is the only class that does not have a special ability.
*************************************************************************************************/
#include "Barbarian.hpp"
#include <iostream>

Barbarian::Barbarian(){
	setArmor(0);
	setStrength(12);
	setNumberDefDie(2);
	setNumberAttDie(2);
	setDefDieSides(6);
	setAttDieSides(6);
	setType("Barbarian");
}

Barbarian::~Barbarian(){

}