#ifndef SWAMP_EVENT_HPP
#define SWAMP_EVENT_HPP 
#include "Event.hpp"
class SwampEvent : public Event
{
public:
	SwampEvent(){};
	SwampEvent(Team*);
	~SwampEvent(){};
	
};
#endif