/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the BlackMage Class. The BlackMage Class is a character within
the unknown Fantasy Game. Black Mage has an Armor rating of 0, Max Health of 10, attacks with 1d4 and
defends with 4d6. The Black Mage class as the special ability to attack with magic missle.
*************************************************************************************************/
#include "BlackMage.hpp"
#include <iostream>

using std::cout;
using std::endl;

BlackMage::BlackMage(){
	setSpeed(5);
	setArmor(0);
	setMaxHealth(10);
	setHealth(getMaxHealth());
	setNumberDefDie(4);
	setNumberAttDie(1);
	setDefDieSides(6);
	setAttDieSides(4);
	setCharacterType(HERO);
	setCharacterClass(BLACK_MAGE);
	setMagicPower(10);
	setIsAlive(true);
	setSlot1(nullptr);
	setSlot2(nullptr);
	setMana(5);
}

BlackMage::~BlackMage(){

}

int BlackMage::magicMissle(){
	int magicDmg = getMagicPower() + roll(getNumberOfAttDie(), getAttDieSides());
	cout << "Black Mage conjures the most magic of missles and attacks for " << magicDmg << " points." << endl;
	return magicDmg;
}