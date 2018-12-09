/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the CaveTroll Class. The CaveTroll Class is a character within
the Heroes Quest Game. CaveTroll has an Armor rating of 8, Max Health of 25, attacks with 3d6 and
defend with 2d5. 
*************************************************************************************************/
#ifndef CAVE_TROLL_HPP
#define CAVE_TROLL_HPP
#include "Character.hpp"
class CaveTroll: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the CaveTroll Class.
*************************************************************************************************/
	CaveTroll();
/**************************************************************************************************
** Description: Deconstructor for the CaveTroll Class.
*************************************************************************************************/
	~CaveTroll();

	
};
#endif