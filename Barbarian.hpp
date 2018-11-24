/**************************************************************************************************
** Author: Jose Garay
** Date: 11/3/2018
** Description: Interface file for the Barbarian Class. The Barbarian Class is a character within
the Fantasy Combat Game. Barbarian has an Armor rating of 0, Strength of 12, attack with 2d6 and
defend with 2d6. The Barbarian class is the only class that does not have a special ability.
*************************************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP 
#include "Character.hpp"
class Barbarian : public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Barbarian Class.
*************************************************************************************************/
	Barbarian();
/**************************************************************************************************
** Description: Deconstructor for the Barbarian Class.
*************************************************************************************************/
	~Barbarian();

	
};
#endif