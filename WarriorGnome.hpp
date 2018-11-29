/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the WarriorGnome Class. The WarriorGnome Class is a character within
the unknown Fantasy Game. WarriorGnome has an Armor rating of 10, Max Health of 30, attacks with 3d6 and
defend with 3d6. The WarriorGnome class is the only class that does not have a special ability.
*************************************************************************************************/
#ifndef WARRIOR_GNOME_HPP 
#define WARRIOR_GNOME_HPP 
#include "Character.hpp"
class WarriorGnome: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the WarriorGnome Class.
*************************************************************************************************/
	WarriorGnome();
/**************************************************************************************************
** Description: Deconstructor for the WarriorGnome Class.
*************************************************************************************************/
	~WarriorGnome();

	
};
#endif