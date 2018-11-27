/**************************************************************************************************
** Author: Jose Garay
** Date: 11/2/2018
** Description: Implementation file for the Character Class. The Character Class is an Abstract 
class that simulates the base charcateristics of a character in a table top game. 
**************************************************************************************************/
#include "Character.hpp"
#include <iostream>

using std::cout;
using std::endl;


Character::Character(){}

Character::~Character(){}

int Character::roll(int die, int sides){
	int total = 0;
	for(int n = 0; n < die; n++){
		total += rand() % sides + 1;
	}
	return total;
}

std::string Character::getCharacterClassString(){
	if(getCharacterClass() == PALADIN){
		return "Paladin";
	}
	else if(getCharacterClass() == ROGUE){
		return "Rogue";
	}
	else if(getCharacterClass() == WHITE_MAGE){
		return "White Mage";
	}
	else if(getCharacterClass() == BLACK_MAGE){
		return "Black Mage";
	}
	else if(getCharacterClass() == WARRIOR_GNOME){
		return "Warrior Gnome";
	}
	else if(getCharacterClass() == ARCHER){
		return "Archer";
	}
}
int Character::attack(){
	//Roll for attack.
	int attack = roll(numberOfAttDie, attDieSides);
	cout << getName() << " the " << getCharacterClassString() << " attacked for " << attack << " points." << endl;

	return attack;
}
void Character::defend(int attack){
	int defense = roll(getNumberOfDefDie(), getDefDieSides());
	int damage = attack - getArmor() - defense;

	if(damage < 0){
		damage = 0;
	}
	setHealth(getHealth()- damage);

	//Displays stats to the console.
	cout << getName() << " the " << getCharacterClassString() << " rolled " << defense << " using " << getNumberOfDefDie() << "d" <<getDefDieSides() << endl;
	cout << getName() << " the " << getCharacterClassString() << " has " << getArmor() << " armor." << endl;
	cout << getName() << " the " << getCharacterClassString() << " defended for " << defense + getArmor() << "." << endl;
	cout << getName() << " the " << getCharacterClassString() << " took " << damage << " point of damage." << endl;
	cout << getName() << " has " << getHealth() << " strength." << endl;
}

void Character::recover(int damageTaken){
	int recovery = damageTaken * 0.5;
	setHealth(getHealth() + recovery);
	cout << getName() << " recovers for " << recovery << " strength points." << endl; 
}