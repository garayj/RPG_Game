/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Interface for the GreaterSword class. The GreaterSword class is an Item that 
is a piece of Equipment. Inherits from the Equipment class. The Greater Sword is a weapon that only
the Paladin class can use. The GreaterSword object gives +10 attack to the Paladin. 
**************************************************************************************************/
#ifndef GREATER_SWORD_HPP
#define GREATER_SWORD_HPP 
#include "Equipment.hpp"
class GreaterSword : public Equipment
{
public:
	//Constructor for the GreaterSword Class.
	GreaterSword();
	//Deconstructor for the GreaterSword Class.
	~GreaterSword();
};
#endif