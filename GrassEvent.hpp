/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The GrassEvent Class extends the Event class and contains the events that occur on
a Grass Space. On a Grass Space, things are simple and easy. The user is able to look at the
inventory, camp, move on, or end the game. No monster battles can occur here.
**************************************************************************************************/
#ifndef GRASS_EVENT_HPP
#define GRASS_EVENT_HPP 
#include "Event.hpp"
class GrassEvent: public Event
{
private:
	//The rest method is if the party decides to camp. 5 HP are gained after a night of sleep.
	void rest(Team*);
public:
	GrassEvent();
	GrassEvent(Team*);
	~GrassEvent();

};
#endif