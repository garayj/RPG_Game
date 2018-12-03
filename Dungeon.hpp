/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Dungeon class. The Dungeon space inherits from the Space 
class. The Dungeon represents a Dungeon on the map. Dungons have the keys that the king is looking 
for but there are also dangerous monsters that live here. Be careful! There are dragons and demons
about!
**************************************************************************************************/
#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include "Space.hpp"
class Dungeon:public Space
{
public:
	Dungeon();
	~Dungeon();
	
};
#endif