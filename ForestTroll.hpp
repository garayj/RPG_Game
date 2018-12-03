/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the ForestTroll Class. The ForestTroll Class is a character within
the Heroes Quest Game. ForestTroll has an Armor rating of 6, Max Health of 20, attacks with 3d4 and
defend with 3d5. 
*************************************************************************************************/
#ifndef FOREST_TROLL_HPP
#define FOREST_TROLL_HPP 
#include "Character.hpp"
class ForestTroll: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the ForestTroll Class.
*************************************************************************************************/
	ForestTroll();
/**************************************************************************************************
** Description: Deconstructor for the ForestTroll Class.
*************************************************************************************************/
	~ForestTroll();

	
};
#endif