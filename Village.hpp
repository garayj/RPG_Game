/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Village class. The Village space inherits from the Space 
class. The Village class represents a Village on the map. Villages are safe places. There are shops
to buy things at, places to rest and revive yourself. Good places to be.
**************************************************************************************************/
#ifndef VILLAGE_HPP
#define VILLAGE_HPP 
#include "Space.hpp"
class Village:public Space
{
public:
	Village();
	~Village();
	
};
#endif