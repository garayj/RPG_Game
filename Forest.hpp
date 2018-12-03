/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Forest Class. The Forest class represents a Forest space on the 
map. The Forest is mostly serene. Bandits and Forest Trolls are about but they are sparce. A mostly
safe area.
**************************************************************************************************/
#ifndef FOREST_HPP
#define FOREST_HPP
#include "Space.hpp"
class Forest:public Space
{
public:
	Forest();
	~Forest();
	
};
#endif