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