/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the MagicShield class. The MagicShield class is an Item that 
inherits from the Equipment class. The Magic Shield can be equip by any class. When held, it gives
+10 defense to any Hero holding it.
**************************************************************************************************/
#include "MagicShield.hpp"

MagicShield::MagicShield(){
	setEffect(10);
	setItemName("Magic Shield");
	setType(ARMOR);
	setDescription("An invisible magic shield.\n");
	setItemType(EQUIPMENT);
}
MagicShield::~MagicShield(){}