/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Grass class. The Grasss space inherits from the Space 
class. The Grass class represents a grass plain on the map. Grass areas are safe places. They are 
good places to rest at and maybe drink a potion or two.
**************************************************************************************************/
#ifndef GRASS_HPP
#define GRASS_HPP 
#include "Space.hpp"
class Grass:public Space
{
public:
	//Constructor for the Grass Class.
	Grass();
	//Deconstructor for the Grass Class.
	~Grass();
	
};
#endif