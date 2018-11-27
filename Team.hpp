/**************************************************************************************************
** Author: Jose Garay
** Date: 11/26/2018
** Description: Interface for the Team class. The Team class simulates a team of characters that 
may be either monsters or heroes. Teams have a location, size, 
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
public:
	Team();
	~Team();

	int getTeamSize(){return teamSize;};
	Character** getCharacters(){return characters;};
	Space* getLocation(){return location;};
	bool getIsTeamAlive(){return isTeamAlive;};

	void setTeamSize(int teamSize){this->teamSize = teamSize;};
	void setHeroes(Character **characters){this->characters = characters;};
	void setLocation(Space *location){this->location = location;};	
	void setIsTeamAlive(bool isTeamAlive){this->isTeamAlive = isTeamAlive;};

	void printCharacters();
};
#endif