/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the MudGoblin Class. The MudGoblin Class is a character within
the Heroes Quest Game. MudGoblin has an Armor rating of 0, Max Health of 10, attacks with 3d3 and
defend with 2d6. 
*************************************************************************************************/
#ifndef MUD_GOBLIN_HPP
#define MUD_GOBLIN_HPP
#include "Character.hpp"
class MudGoblin: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the MudGoblin Class.
*************************************************************************************************/
	MudGoblin();
/**************************************************************************************************
** Description: Deconstructor for the MudGoblin Class.
*************************************************************************************************/
	~MudGoblin();

	
};
#endif