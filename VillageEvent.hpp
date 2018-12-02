#ifndef VILLAGE_EVENT_HPP
#define VILLAGE_EVENT_HPP 
#include "Event.hpp"
#include "Team.hpp"
#include "Item.hpp"
class VillageEvent : public Event
{
public:
	VillageEvent(Team*);
	~VillageEvent(){};

	void rest();
	Item* createItem(int);
	
};
#endif