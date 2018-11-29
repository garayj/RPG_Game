/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the Rogue Class. The Rogue Class is a character within
the unknown Fantasy Game. Rogue has an Armor rating of 10, Max Health of 30, attacks with 3d6 and
defend with 3d6. The Rogue class is the only class that does not have a special ability.
*************************************************************************************************/
#ifndef ROGUE_HPP
#define ROGUE_HPP
#include "Character.hpp"
class Rogue: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Rogue Class.
*************************************************************************************************/
	Rogue();
/**************************************************************************************************
** Description: Deconstructor for the Rogue Class.
*************************************************************************************************/
	~Rogue();

	
};
#endif