/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the Crossbow class. The Crossbow Item is a piece of Equipment
that inherits from the Equipment class. Only the Ranger class and hold this. Gives an additional 
+15 to attack to Rangers.
**************************************************************************************************/
#include "Crossbow.hpp"

Crossbow::Crossbow(){
	setEffect(15);
	setItemName("Crossbow");
	setType(WEAPON);
	setDescription("Shoots arrows n stuff.\n");
	setItemType(EQUIPMENT);
	setClassType(RANGER);
}
Crossbow::~Crossbow(){}