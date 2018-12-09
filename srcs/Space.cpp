/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: The Space class represents a space on the board. Each space contains four directions,
a pointer to a pointer of monsters, and a count of those monsters. The entire Map is made up of 36
spaces that the user can traverse using the w a s d keys. There is also a spaceType enum that is 
used to distingush which type of space each space is. This is an abstract class.
**************************************************************************************************/
#include "Space.hpp"
Space::Space(){}

Space::~Space(){}