/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the GreaterSword class. The GreaterSword class is an Item that 
is a piece of Equipment. Inherits from the Equipment class. The Greater Sword is a weapon that only
the Paladin class can use. The GreaterSword object gives +10 attack to the Paladin. 
**************************************************************************************************/
#include "GreaterSword.hpp"

GreaterSword::GreaterSword(){
	setEffect(10);
	setItemName("Greater Sword");
	setType(WEAPON);
	setDescription("A really sharp sword to poke stuff. There's a legend behind it I think. It glows green.\n");
	setItemType(EQUIPMENT);
	setClassType(PALADIN);
}
GreaterSword::~GreaterSword(){}