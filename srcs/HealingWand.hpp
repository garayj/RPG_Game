/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Interface for the HealingWand class. The HealingWand class is an Item that 
inherits from the Equipment class. The Healing Wand class is an object that only the WhiteMage class
can use. Gives +10 to the White Mage when equip.
**************************************************************************************************/
#ifndef HEALING_WAND_HPP 
#define HEALING_WAND_HPP 
#include "Equipment.hpp"
class HealingWand : public Equipment
{
public:
	//Constructor for the HealingWand Class.
	HealingWand();
	//Deconstructor for the HealingWand Class.
	~HealingWand();
};
#endif