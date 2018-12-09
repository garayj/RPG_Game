/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the Dragon Class. The Dragon Class is a character within
the Heroes Quest Game. Dragon has an Armor rating of 15, Max Health of 50, attacks with 5d5 and
defend with 3d6. 
*************************************************************************************************/
#ifndef DRAGON_HPP 
#define DRAGON_HPP 
#include "Character.hpp"
class Dragon: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Dragon Class.
*************************************************************************************************/
	Dragon();
/**************************************************************************************************
** Description: Deconstructor for the Dragon Class.
*************************************************************************************************/
	~Dragon();

	
};
#endif