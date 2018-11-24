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
int Character::attack(){
	//Roll for attack.
	int attack = roll(numberOfAttDie, attDieSides);
	cout << getName() << " the " << getType() << " attacked for " << attack << " points." << endl;

	return attack;
}
void Character::defend(int attack){
	int defense = roll(getNumberOfDefDie(), getDefDieSides());
	int damage = attack - getArmor() - defense;

	if(damage < 0){
		damage = 0;
	}
	setStrength(getStrength()- damage);

	//Displays stats to the console.
	cout << getName() << " the " << getType() << " rolled " << defense << " using " << getNumberOfDefDie() << "d" <<getDefDieSides() << endl;
	cout << getName() << " the " << getType() << " has " << getArmor() << " armor." << endl;
	cout << getName() << " the " << getType() << " defended for " << defense + getArmor() << "." << endl;
	cout << getName() << " the " << getType() << " took " << damage << " point of damage." << endl;
	cout << getName() << " has " << getStrength() << " strength." << endl;
}

void Character::recover(int damageTaken){
	int recovery = damageTaken * 0.5;
	setStrength(getStrength() + recovery);
	cout << getName() << " recovers for " << recovery << " strength points." << endl; 
}