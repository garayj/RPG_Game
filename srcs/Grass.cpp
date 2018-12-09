/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation for the Grass class. The Grasss space inherits from the Space 
class. The Grass class represents a grass plain on the map. Grass areas are safe places. They are 
good places to rest at and maybe drink a potion or two.
**************************************************************************************************/
#include "Grass.hpp"

Grass::Grass(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(GRASS);
}

Grass::~Grass(){}