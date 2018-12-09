/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The Interface File for the Equipment Class. Abstract class that carries all the 
basic attributes of the Equipment that will be used in the game. Inherits from the Item class.
**************************************************************************************************/
#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP 
#include "Item.hpp"
#include "characterClass.hpp"

enum equipmentType{ARMOR, WEAPON};
class Equipment : public Item
{
protected:
	characterClass classType;
	equipmentType type;	
public:
	//Constructor for the Equipment Class.
	Equipment();
	//Deconstructor for the Equipment Class.
	virtual ~Equipment()=0;

	//Getter Methods for the data members of the Equipment Class
	equipmentType getType(){return type;};
	characterClass getClassType(){return classType;};


	//Setter Methods for the data members of the Equipment Class
	void setType(equipmentType type){this->type = type;};
	void setClassType(characterClass classType){this->classType = classType;};
	
};
#endif