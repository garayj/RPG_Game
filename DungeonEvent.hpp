#ifndef DUNGEON_EVENT_HPP
#define DUNGEON_EVENT_HPP 
#include "DangerEvent.hpp"
class DungeonEvent : public DangerEvent
{
public:
	DungeonEvent(Team*);
	~DungeonEvent(){};
	
};
#endif