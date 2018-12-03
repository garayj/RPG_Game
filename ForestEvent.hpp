#ifndef FOREST_EVENT_HPP
#define FOREST_EVENT_HPP 
#include "DangerEvent.hpp"
class ForestEvent : public DangerEvent
{
public:
	ForestEvent(Team *);
	~ForestEvent(){};
	
};
#endif