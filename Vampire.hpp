/**************************************************************************************************
** Author: Jose Garay
** Date: 11/2/2018
** Description: Interface for the Vampire class. The Vampire class simulates a vampire in a table
top style game. The Vampire class has an armor of 1, strength of 18, attacks with 1d12, and defends
with 1d6. The Vampire has a special ability to charm its way out of an attack. 50% of the time, it
works every time. The Vampire class inherits from the Character class.
**************************************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP 
#include "Character.hpp"
class Vampire:public Character{
private:
/**************************************************************************************************
** Description: Private Method. Returns a boolean and takes no input. If it returns true, Vampire
used charm to get out of an attack.
**************************************************************************************************/
	bool charm();
public:	
/**************************************************************************************************
** Description: Constructor for the Vampire class.
**************************************************************************************************/
	Vampire();
/**************************************************************************************************
** Description: Deconstructor for the Vampire class.
**************************************************************************************************/
	~Vampire();
/**************************************************************************************************
** Description: Public method. Takes an integer as input and returns nothing. The defend method,
calls on defendRoll to simulate rolling of die to defend. Can call charm to dodge an attack.
**************************************************************************************************/
	void defend(int) override;
};
#endif