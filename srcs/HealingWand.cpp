/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the HealingWand class. The HealingWand class is an Item that 
inherits from the Equipment class. The Healing Wand class is an object that only the WhiteMage class
can use. Gives +10 to the White Mage when equip.
**************************************************************************************************/
#include "HealingWand.hpp"

HealingWand::HealingWand(){
	setEffect(10);
	setItemName("Healing Wand");
	setType(WEAPON);
	setDescription("A unicorns......horn.\n");
	setItemType(EQUIPMENT);
	setClassType(WHITE_MAGE);
}
HealingWand::~HealingWand(){}