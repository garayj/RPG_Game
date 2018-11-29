#ifndef DUNGEON_EVENT_HPP
#define DUNGEON_EVENT_HPP 
#include "Event.hpp"
class DungeonEvent : public Event
{
public:
	DungeonEvent(){};
	DungeonEvent(Team*);
	~DungeonEvent(){};
	
};
#endif