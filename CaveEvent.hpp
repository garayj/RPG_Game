#ifndef CAVE_EVENT_HPP
#define CAVE_EVENT_HPP 
#include "Event.hpp"
class CaveEvent : public Event
{
public:
	CaveEvent(){};
	CaveEvent(Team*);
	~CaveEvent(){};
};
#endif