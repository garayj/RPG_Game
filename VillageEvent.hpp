#ifndef VILLAGE_EVENT_HPP
#define VILLAGE_EVENT_HPP 
#include "Event.hpp"
class VillageEvent : public Event
{
public:
	VillageEvent(){};
	VillageEvent(Team*);
	~VillageEvent(){};
	
};
#endif