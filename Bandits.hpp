/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the Bandits Class. The Bandits Class is a character within
the Heroes Quest Game. Bandits has an Armor rating of 7, Max Health of 12, attacks with 2d6 and
defend with 1d6. 
*************************************************************************************************/
#ifndef BANDITS_HPP 
#define BANDITS_HPP 
#include "Character.hpp"
class Bandits: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Bandits Class.
*************************************************************************************************/
	Bandits();
/**************************************************************************************************
** Description: Deconstructor for the Bandits Class.
*************************************************************************************************/
	~Bandits();

	
};
#endif
