/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The Key Class inherits from the Item class. Keys are what you are ultimately looking
for. If you have 4 in your possession before the 30th day you win. They don't do anything though.
**************************************************************************************************/
#ifndef KEY_HPP
#define KEY_HPP 
#include "Item.hpp"
class Key:public Item
{
public:
	//Constructor for the Key Class.
	Key();
	//Deconstructor for the Key Class.
	~Key();
	
};
#endif