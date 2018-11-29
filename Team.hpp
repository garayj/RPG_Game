/**************************************************************************************************
** Author: Jose Garay
** Date: 11/26/2018
** Description: Interface for the Team class. The Team class simulates a team of characters that 
may be either monsters or heroes. Teams have a location, size, Characters, an inventory, and a 
boolean data member to check whether the Team is alive or not.
**************************************************************************************************/
#ifndef TEAM_HPP
#define TEAM_HPP 
#include "Space.hpp"
#include "Character.hpp"

class Team
{
private:
	bool isTeamAlive;
	int teamSize;
	Character **characters;
	Space *location;
	// Item **inventory;
public:
	Team(int);
	~Team();





	//Getter Functions for the Team class data members
	int getTeamSize(){return teamSize;};
	Character** getCharacters(){return characters;};
	Space* getLocation(){return location;};
	bool getIsTeamAlive(){return isTeamAlive;};





	//Setter Functions for the Team class data members
	void setTeamSize(int teamSize){this->teamSize = teamSize;};
	void setCharacters(Character **characters){this->characters = characters;};
	void setLocation(Space *location){this->location = location;};	
	void setIsTeamAlive(bool isTeamAlive){this->isTeamAlive = isTeamAlive;};




	//Checks if the team any Character in the team is still alive.
	bool teamAliveStatus();
	//Prints out all the characters in the Team.
	void printCharacters();
};
#endif