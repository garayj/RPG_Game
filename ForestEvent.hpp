#ifndef FOREST_EVENT_HPP
#define FOREST_EVENT_HPP 
#include "Event.hpp"
class ForestEvent : public Event
{
public:
	ForestEvent(){};
	ForestEvent(Team *);
	~ForestEvent(){};
	
};
#endif