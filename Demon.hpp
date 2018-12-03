/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the Demon Class. The Demon Class is a character within
the Heroes Quest Game. Demon has an Armor rating of 5, Max Health of 10, attacks with 3d3 and
defend with 3d3. 
*************************************************************************************************/
#ifndef DEMON_HPP
#define DEMON_HPP
#include "Character.hpp"
class Demon: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the Demon Class.
*************************************************************************************************/
	Demon();
/**************************************************************************************************
** Description: Deconstructor for the Demon Class.
*************************************************************************************************/
	~Demon();

	
};
#endif