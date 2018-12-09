/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The SwapEvent Class extends the Event class and contains the events that occur on
a Swamp Space. On a Swamp Space, things are dangerous. If there are monsters alive, the user has a
small chance to sneak on by or walk into trouble. If the user has already defeated the monsters,
the user walks into no more trouble. Zombies and mud goblins live here.
**************************************************************************************************/
#ifndef SWAMP_EVENT_HPP
#define SWAMP_EVENT_HPP 
#include "DangerEvent.hpp"

class SwampEvent : public DangerEvent
{
private:


public:
	SwampEvent(Team*,Space*);
	~SwampEvent(){};


};
#endif