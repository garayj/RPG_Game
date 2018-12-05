/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the Crossbow class. The Crossbow Item is a piece of Equipment
that inherits from the Equipment class. Only the Ranger class and hold this. Gives an additional 
+15 to attack to Rangers.
**************************************************************************************************/
#ifndef CROSSBOW_HPP 
#define CROSSBOW_HPP
#include "Equipment.hpp"
class Crossbow : public Equipment
{
public:
	//Constructor for the Crossbow Class.
	Crossbow();
	//Deconstructor for the Crossbow Class.
	~Crossbow();
};
#endif