/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface file for the GiantSpider Class. The GiantSpider Class is a character within
the Heroes Quest Game. GiantSpider has an Armor rating of 0, Max Health of 10, attacks with 2d6 and
defend with 1d6. 
*************************************************************************************************/
#ifndef GIANT_SPIDER_HPP
#define GIANT_SPIDER_HPP
#include "Character.hpp"
class GiantSpider: public Character
{
public:
/**************************************************************************************************
** Description: Constructor for the GiantSpider Class.
*************************************************************************************************/
	GiantSpider();
/**************************************************************************************************
** Description: Deconstructor for the GiantSpider Class.
*************************************************************************************************/
	~GiantSpider();

	
};
#endif