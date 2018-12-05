/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the BattleWand class. The Battle Wand is an Item is a piece of 
Equipment. BattleWant inherits from the Equipment class. Only the BlackMage class can use the Battle
Wand. When equip, the Battle Wand gives a +15 damage to the Black Mages attack.
**************************************************************************************************/
#include "BattleWand.hpp"

BattleWand::BattleWand(){
	setEffect(15);
	setItemName("Battle Wand");
	setType(WEAPON);
	setDescription("Literally just a stick.\n");
	setItemType(EQUIPMENT);
	setClassType(BLACK_MAGE);
}
BattleWand::~BattleWand(){}