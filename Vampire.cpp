/**************************************************************************************************
** Author: Jose Garay** Date: 11/2/2018
** Description: Interface for the Vampire class. The Vampire class simulates a vampire in a table
top style game. The Vampire class has an armor of 1, strength of 18, attacks with 1d12, and defends
with 1d6. The Vampire has a special ability to charm its way out of an attack. 50% of the time, it
works every time. The Vampire class inherits from the Character class.
**************************************************************************************************/
#include "Vampire.hpp"
#include <iostream>

using std::cout;
using std::endl;

Vampire::Vampire(){
	setCharacterType(HERO);
	setCharacterClass(ROGUE);
	setArmor(1);
	setMaxHealth(18);
	setHealth(getMaxHealth());
	setNumberDefDie(1);
	setNumberAttDie(1);
	setDefDieSides(6);
	setAttDieSides(12);
}

Vampire::~Vampire(){
}

bool Vampire::charm(){
	return rand() % 2;
}

void Vampire::defend(int attack){
	//If charm returns true, the Vampire takes no damage.
	if(charm()){
		cout << getName() << " the " << getCharacterClassString() << " is one smooth talker. " << getName() << " takes no damage." << endl;
		return;
	}
	else{
		int defense = roll(getNumberOfDefDie(), getDefDieSides());
		int damage = attack - getArmor() - defense;

		if(damage < 0){
			damage = 0;
		}

		cout << getName() << " the " << getCharacterClassString() << " rolled " << defense << " using " << getNumberOfDefDie() << "d" <<getDefDieSides() << endl;
		cout << getName() << " the " << getCharacterClassString() << " has " << getArmor() << " armor." << endl;
		cout << getName() << " the " << getCharacterClassString() << " defended for " << defense + getArmor() << "." << endl;
		cout << getName() << " the " << getCharacterClassString() << " took " << damage << " point of damage." << endl;


		cout << getName() << " has " << getHealth() << " strength." << endl;
		//Subtract damage from strength.
		setHealth(getHealth()- damage);

	}
}

