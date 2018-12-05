/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the SharpDagger class. The SharpDagger Item is a piece of Equipment
that inherits from the Equipment class. Only the Rogue class and hold this. Gives an additional 
+30 to attack to Rogues.
**************************************************************************************************/
#include "SharpDagger.hpp"

SharpDagger::SharpDagger(){
	setEffect(30);
	setItemName("Sharp Dagger");
	setType(WEAPON);
	setDescription("A butter knife.\n");
	setItemType(EQUIPMENT);
	setClassType(ROGUE);
}
SharpDagger::~SharpDagger(){}