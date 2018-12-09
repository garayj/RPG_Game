/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Implementation for the Village class. The Village space inherits from the Space 
class. The Village class represents a Village on the map. Villages are safe places. There are shops
to buy things at, places to rest and revive yourself. Good places to be.
**************************************************************************************************/
#include "Village.hpp"

Village::Village(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(VILLAGE);
}

Village::~Village(){}