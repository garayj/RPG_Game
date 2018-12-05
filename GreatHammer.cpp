/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the GreatHammer class. The GreatHammer class is an Item that is
a piece of Equipment. The GreatHammer inherits from the Equipment class. This Weapon can only be
equipped by the WarriorGnome class. Gives +10 attack damage to every attack.
**************************************************************************************************/
#include "GreatHammer.hpp"

GreatHammer::GreatHammer(){
	setEffect(10);
	setItemName("Great Hammer");
	setType(WEAPON);
	setDescription("IT\'S HAMMER TIME.\n");
	setItemType(EQUIPMENT);
	setClassType(WARRIOR_GNOME);
}
GreatHammer::~GreatHammer(){}