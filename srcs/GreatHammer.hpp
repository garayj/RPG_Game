/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Interface for the GreatHammer class. The GreatHammer class is an Item that is
a piece of Equipment. The GreatHammer inherits from the Equipment class. This Weapon can only be
equipped by the WarriorGnome class. Gives +10 attack damage to every attack.
**************************************************************************************************/
#ifndef GREAT_HAMMER_HPP 
#define GREAT_HAMMER_HPP 
#include "Equipment.hpp"
class GreatHammer : public Equipment
{
public:
	//Constructor for the GreatHammer Class.
	GreatHammer();
	//Dexonstructor for the GreatHammer Class.
	~GreatHammer();
};
#endif