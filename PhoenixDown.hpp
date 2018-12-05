/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: The PhoenixDown Class inherits from the Potion class. If a hero is killed from 
battle, another hero may revive him using a Phoenix Down.
**************************************************************************************************/
#ifndef PHOENIX_DOWN_HPP 
#define PHOENIX_DOWN_HPP 
#include "Potion.hpp"
#include "Character.hpp"
class PhoenixDown : public Potion 
{
public:
	PhoenixDown();
	~PhoenixDown();
	virtual void usePotion(Character * hero);
	
};
#endif