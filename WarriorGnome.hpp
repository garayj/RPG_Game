/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Implementation file for the WarriorGnome Class. The WarriorGnome Class is a character within
the unknown Fantasy Game. WarriorGnome has an Armor rating of 7, Max Health of 20, attacks with 8d8 and
defend with 5d5. 
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