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

Character::~Character(){
	if(getSlot1() != nullptr){
		delete slot1;
	}
	if(getSlot2() != nullptr){
		delete slot2;
	}
}

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
	else if(getCharacterClass() == MUD_GOBLIN){
		return "Mud Goblin";
	}
	else if(getCharacterClass() == ZOMBIE){
		return "Zombie";
	}
	else if(getCharacterClass() == GIANTSPIDER){
		return "Giant Spider";
	}
	else if(getCharacterClass() == CAVE_TROLL){
		return "Cave Troll";
	}
	else if(getCharacterClass() == DEMON){
		return "Demon";
	}
	else if(getCharacterClass() == DRAGON){
		return "Dragon";
	}
	else if(getCharacterClass() == BANDITS){
		return "Bandits";
	}
	else if(getCharacterClass() == FOREST_TROLL){
		return "Forest Troll";
	}
	else{
		return "Ranger";
	}
}
int Character::attack(){
	//Roll for attack.
	int attack = roll(numberOfAttDie, attDieSides);
	if(slot1 != nullptr && slot1->getType() == WEAPON){
		attack += slot1->getEffect();
	}
	if(slot2 != nullptr && slot2->getType() == WEAPON){
		attack += slot2->getEffect();
	}
	return attack;
}
void Character::defend(int attack){

	int defense = roll(getNumberOfDefDie(), getDefDieSides());

	if(slot1 != nullptr && slot1->getType() == ARMOR){
		defense += slot1->getEffect();
	}
	if(slot2 != nullptr && slot2->getType() == ARMOR){
		defense += slot2->getEffect();
	}
	int damage = attack - getArmor() - defense;

	if(damage < 0){
		damage = 0;
	}
	setHealth(getHealth()- damage);

	//Displays stats to the console.
	cout << getCharacterClassString() << " has " << getArmor() << " armor." << endl;
	cout << getCharacterClassString() << " has " << getArmor() << " armor and defended for " << defense + getArmor() << "." << endl;
	cout << getCharacterClassString() << " took " << damage << " point of damage." << endl;
	cout << getCharacterClassString() << " has " << getHealth() << " strength." << endl;
}

void Character::recover(int damageTaken){
	int recovery = damageTaken * 0.5;
	setHealth(getHealth() + recovery);
	cout << getName() << " recovers for " << recovery << " strength points." << endl; 
}