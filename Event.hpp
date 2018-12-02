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
class Event
{
protected:
	Menu *menu;

public:
	Event();
	virtual ~Event()=0;
	// virtual void fight()=0;

	//Getter functions for the private data members.
	Menu *getMenu(){return menu;};

	//Setter functions for the private data members.
	void setMenu(Menu *menu){this->menu = menu;};
	
};
#endif