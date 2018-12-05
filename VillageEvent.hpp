/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The VillageEvent Class inherits from the the Event class and contains the events 
that occur on a Village Space. On a Village Space, things are hustle and bustle. The user is able 
to look at the inventory, go sleep at the near by inn, move on, buy items at the local shop, or end 
the game. No monster battles can occur here.
**************************************************************************************************/
#ifndef VILLAGE_EVENT_HPP
#define VILLAGE_EVENT_HPP 
#include "Event.hpp"
#include "Team.hpp"
#include "Item.hpp"
class VillageEvent : public Event
{
protected:	
	//The createItem method creates an Item after you purchase it and is placed in your inventory.
	Item* createItem(int);
public:
	VillageEvent(Team*);
	~VillageEvent(){};

	//The rest Method simulates the party sleeping at a nearby inn and recovers for all health points
	//and mana.
	void rest();
	
};
#endif