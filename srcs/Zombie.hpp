/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the Zombie Class. The Zombie Class is a character within
the Heroes Quest Game. Zombie has an Armor rating of 0, Max Health of 15, attacks with 3d6 and
defend with 1d6. 
*************************************************************************************************/
#ifndef ZOMBIE_HPP 
#define ZOMBIE_HPP 
#include "Character.hpp"
class Zombie: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Zombie Class.
*************************************************************************************************/
	Zombie();
/**************************************************************************************************
** Description: Deconstructor for the Zombie Class.
*************************************************************************************************/
	~Zombie();

	
};
#endif