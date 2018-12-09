/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Swamp Class. The Swamp class represents a Swamp space on the 
map. The Swamp class represents a swampy area that's spooky and scary. Zombies and Mud Goblins live
here. Don't get stuck here!
**************************************************************************************************/
#ifndef SWAMP_HPP
#define SWAMP_HPP
#include "Space.hpp"
class Swamp:public Space
{
public:
	Swamp();
	~Swamp();
	
};
#endif