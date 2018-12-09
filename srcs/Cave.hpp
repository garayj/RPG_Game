/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Cave class. The Cave space inherits from the Space class. The 
Cave represents a Cave on the map. Caves are dangerous places. There are powerful cave trolls and
giant spiders about. Not a fun place to be. Stay safe!
**************************************************************************************************/
#ifndef CAVE_HPP
#define CAVE_HPP 
#include "Space.hpp"
class Cave:public Space
{
public:
	//Constructor for the Cave Class.
	Cave();
	//Deconstructor for the Cave Class.
	~Cave();
	
};
#endif