/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The ForestEvent Class extends the Event class and contains the events that occur on
a Forest Space. On a Forest Space, things are not very dangerous. If there are monsters alive, the 
user has a low chance of fighting them but the reward is high if you are lucky enough to find them 
and beat them.
**************************************************************************************************/
#ifndef FOREST_EVENT_HPP
#define FOREST_EVENT_HPP 
#include "DangerEvent.hpp"
class ForestEvent : public DangerEvent
{
public:
	ForestEvent(Team *, Space*);
	~ForestEvent(){};
	
};
#endif