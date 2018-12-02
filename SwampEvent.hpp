#ifndef SWAMP_EVENT_HPP
#define SWAMP_EVENT_HPP 
#include "Event.hpp"
#include "Space.hpp"
#include "Character.hpp"
class SwampEvent : public Event
{
private:
	//Checks to see if there are monsters alive in the space.
	bool areMonstersAlive(Space*);

	//The case that a monster dies.
	void monsterDies(Character*);
	
	//The case that a hero dies.
	void heroDies(Character*);

	//Method that simulates the encounter between the heroes and monsters on the space.
	void encounter(Team*, Space*);
public:
	SwampEvent(){};
	SwampEvent(Team*,Space*);
	~SwampEvent(){};


};
#endif