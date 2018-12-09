/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Implementation for the DefensePotion class. The DefensePotion is an Item is Potion
that you can use to permanantly increase your defense rating. The DefensePotion inherits from the 
Potion class.
**************************************************************************************************/
#ifndef DEFENSE_POTION_HPP
#define DEFENSE_POTION_HPP 
#include "Potion.hpp"
#include "Character.hpp"
class DefensePotion : public Potion 
{
public:
	//Constructor for the Defense Potion Class.
	DefensePotion();
	//Deconstructor for the DefensePotion Class.
	~DefensePotion();
	//Defines the usePotion method for the DefensePotion class. Adds 5 to Armor and takes in a
	//Character pointer object to use the potion on.
	virtual void usePotion(Character *hero);
	
};
#endif