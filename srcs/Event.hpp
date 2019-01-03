/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The Event Class is an abstract class that will be used to contain all the events
that will occur on each space on the board.
**************************************************************************************************/
#ifndef EVENT_HPP
#define EVENT_HPP 
#include "Menu.hpp"
#include "Team.hpp"
#include "Space.hpp"
class Event
{
protected:
	Space *space;
	Menu menu;
	Team *heroes;

public:
	//Constructor for the Event Class.
	Event();
	//Deconstructor for the Event Class. Pure Virtual Function.
	virtual ~Event()=0;
	// virtual void fight()=0;
	bool inventoryAction();	

	//Getter functions for the private data members.
	Menu getMenu(){return menu;};
	Team *getHeroes(){return heroes;};
	Space *getSpace(){return space;};

	//Setter functions for the private data members.
	void setMenu(Menu menu){this->menu = menu;};
	void setHeroes(Team *heroes){this->heroes = heroes;};
	void setSpace(Space *space){this->space = space;};
	
};
#endif