/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Interface for the HealthPotion class. The HealthPotion class is an Item that 
inherits from the Potion class. A HealthPotion can be used to heal for 5 HP.
**************************************************************************************************/
#ifndef HEALTH_POTION_HPP
#define HEALTH_POTION_HPP 
#include "Potion.hpp"
#include "Character.hpp"
class HealthPotion : public Potion 
{
public:
	//Constructor for the Healing Potion Class.
	HealthPotion();
	//Deconstructor for the HealingPotion Class.
	~HealthPotion();
	//Heals unless the the Hero is dead.
	virtual void usePotion(Character * hero);
	
};
#endif