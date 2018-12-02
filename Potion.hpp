/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Potion Class. The Potion class is an abstract class that has the
basic components of a potion object for the Hero's Quest game. The Potion class inherits from the 
Item class.
**************************************************************************************************/
#ifndef POTION_HPP
#define POTION_HPP 
#include "Item.hpp"
#include "Character.hpp"
class Potion : public Item
{
protected:
	bool isBirdFeather;
public:
	Potion();
	~Potion();

	//Getter Function. Returns the isBirdFeather boolean data member.
	bool getIsBirdFeather(){return isBirdFeather;};

	//Setter Function. Sets the isBirdFeather boolean data member.
	void setIsBirdFeather(bool isBirdFeather){this->isBirdFeather = isBirdFeather;};

	//The usePotion method is pure abstract function here. Describes how the usePotion function will
	//be used.
	virtual void usePotion(Character *)=0;
	
};
#endif