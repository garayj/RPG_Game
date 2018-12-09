/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The Key Class inherits from the Item class. Keys are what you are ultimately looking
for. If you have 4 in your possession before the 30th day you win. They don't do anything though.
**************************************************************************************************/
#include "Key.hpp"

Key::Key(){
	setItemType(KEY);
	setEffect(0);
	setItemName("Key");
	setDescription("Collect all 4 of these to win a prize or something.");
}

Key::~Key(){}