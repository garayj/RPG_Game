/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation file for the GiantSpider Class. The GiantSpider Class is a character within
the Heroes Quest Game. GiantSpider has an Armor rating of 0, Max Health of 10, attacks with 2d3 and
defend with 1d6. 
*************************************************************************************************/
#include "GiantSpider.hpp"
#include <iostream>

GiantSpider::GiantSpider(){
	setIsAlive(true);
	setArmor(0);
	setMaxHealth(10);
	setSpeed(10);
	setHealth(getMaxHealth());
	setNumberDefDie(1);
	setNumberAttDie(2);
	setDefDieSides(6);
	setAttDieSides(3);
	setCharacterType(MONSTER);
	setCharacterClass(GIANTSPIDER);
	setSlot1(nullptr);
	setSlot2(nullptr);
}

GiantSpider::~GiantSpider(){

}