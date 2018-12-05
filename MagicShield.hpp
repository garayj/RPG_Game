/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Interface for the MagicShield class. The MagicShield class is an Item that 
inherits from the Equipment class. The Magic Shield can be equip by any class. When held, it gives
+10 defense to any Hero holding it.
**************************************************************************************************/
#ifndef MAGIC_SHIELD_HPP 
#define MAGIC_SHIELD_HPP 
#include "Equipment.hpp"
class MagicShield : public Equipment
{
public:
	//Constructor for the MagicShield Class.
	MagicShield();
	//Deconstructor for the MagicShield Class.
	~MagicShield();
};
#endif