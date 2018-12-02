#ifndef CAVE_EVENT_HPP
#define CAVE_EVENT_HPP 
#include "Event.hpp"
class CaveEvent : public Event
{
public:
	CaveEvent(Team*);
	~CaveEvent(){};
};
#endif