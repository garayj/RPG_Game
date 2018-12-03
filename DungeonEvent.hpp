/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The DungeonEvent Class extends the Event class and contains the events that occur on
a Dungeon Space. On a Dungeon Space, things are the most dangerous. If there are monsters alive, you
have to fight them. The chance of encounter is 100%. The enemies are also pretty strong. There are
keys here as reward though.
**************************************************************************************************/
#ifndef DUNGEON_EVENT_HPP
#define DUNGEON_EVENT_HPP 
#include "DangerEvent.hpp"
class DungeonEvent : public DangerEvent
{
public:
	DungeonEvent(Team*, Space*);
	~DungeonEvent(){};
	
};
#endif