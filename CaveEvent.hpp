#ifndef CAVE_EVENT_HPP
#define CAVE_EVENT_HPP 
#include "DangerEvent.hpp"
class CaveEvent : public DangerEvent 
{
public:
	CaveEvent(Team*);
	~CaveEvent(){};
};
#endif