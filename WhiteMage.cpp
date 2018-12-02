/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the WhiteMage Class. The WhiteMage Class is a character within
the unknown Fantasy Game. White Mage has an Armor rating of 0, Max Health of 10, attacks with 1d4 and
defends with 4d6. The White Mage class as the special ability to heal party or hero.
*************************************************************************************************/
#include "WhiteMage.hpp"
#include <iostream>

using std::cout;
using std::endl;

WhiteMage::WhiteMage(){
	setIsAlive(true);
	setSlot1(nullptr);
	setSlot2(nullptr);
	setArmor(0);
	setMaxHealth(10);
	setHealth(getMaxHealth());
	setNumberDefDie(4);
	setNumberAttDie(1);
	setDefDieSides(6);
	setAttDieSides(4);
	setCharacterType(HERO);
	setCharacterClass(WHITE_MAGE);
	setMagicPower(10);
	setMaxMana(5);
	setMana(getMaxMana());
	setSpeed(5);
}

WhiteMage::~WhiteMage(){

}

void WhiteMage::healOne(Character *hurtCharacter){
	int heal = rand() % getMagicPower() + 1;
	if(heal + hurtCharacter->getHealth() > hurtCharacter->getMaxHealth()){
		hurtCharacter->setHealth(hurtCharacter->getMaxHealth());
	}
	else{
		hurtCharacter->setHealth(heal + hurtCharacter->getHealth());
	}
	setMana(getMana() -1);
}

void WhiteMage::healParty(Team *hurtTeam){
	for(int n = 0; n < hurtTeam->getTeamSize(); n++){
		if(hurtTeam->getCharacters()[n]->getIsAlive()){
			healOne(hurtTeam->getCharacters()[n]);
			setMana(getMana() + 1);
		}

	}
	setMana(getMana() - 5);
}