/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Interface for the SharpDagger class. The SharpDagger Item is a piece of Equipment
that inherits from the Equipment class. Only the Rogue class and hold this. Gives an additional 
+30 to attack to Rogues.
**************************************************************************************************/
#ifndef SHARP_DAGGER_HPP
#define SHARP_DAGGER_HPP 
#include "Equipment.hpp"
class SharpDagger : public Equipment
{
public:
	SharpDagger();
	~SharpDagger();
};
#endif