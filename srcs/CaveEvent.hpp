/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The CaveEvent class simulates what happens on the Cave Space. The CaveEvent class
takes the monsters that are on the Cave Space and has the heroes fight them at random with a high
probability that they will fight. The Hero is rewarded with a random amount of gold that is above
1500G for beating the monsters. 
**************************************************************************************************/
#ifndef CAVE_EVENT_HPP
#define CAVE_EVENT_HPP 
#include "DangerEvent.hpp"
class CaveEvent : public DangerEvent 
{
public:
	//Constructor for the CaveEvent Class.
	CaveEvent(Team*, Space*);
	//Deconstructor for the CaveEvent Class.
	~CaveEvent(){};
};
#endif