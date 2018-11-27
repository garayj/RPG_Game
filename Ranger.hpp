/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the Ranger Class. The Ranger Class is a character within
the unknown Fantasy Game. Ranger has an Armor rating of 3, Max Health of 15, attacks with 4d4 and
defend with 2d6. 
*************************************************************************************************/
#ifndef RANGER_HPP 
#define RANGER_HPP 
#include "Character.hpp"
class Ranger: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Ranger Class.
*************************************************************************************************/
	Ranger();
/**************************************************************************************************
** Description: Deconstructor for the Ranger Class.
*************************************************************************************************/
	~Ranger();

	
};
#endif