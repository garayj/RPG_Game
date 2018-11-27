/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the Paladin Class. The Paladin Class is a character within
the unknown Fantasy Game. Paladin has an Armor rating of 10, Max Health of 30, attacks with 3d6 and
defend with 3d6. The Paladin class is the only class that does not have a special ability.
*************************************************************************************************/
#ifndef PALADIN_HPP
#define PALADIN_HPP
#include "Character.hpp"
class Paladin: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Paladin Class.
*************************************************************************************************/
	Paladin();
/**************************************************************************************************
** Description: Deconstructor for the Paladin Class.
*************************************************************************************************/
	~Paladin();

	
};
#endif