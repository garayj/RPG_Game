#ifndef TEAM_HPP
#define TEAM_HPP 
#include "Space.hpp"
#include "Character.hpp"

class Team
{
private:
	int teamSize;
	Character **heroes;
	Space *location;
public:
	Team();
	~Team();

	int getTeamSize(){return teamSize;};
	Character** getHeroes(){return heroes;};
	Space* getLocation(){return location;};

	void setTeamSize(int teamSize){this->teamSize = teamSize;};
	void setHeroes(Character **heroes){this->heroes = heroes;};
	void setLocation(Space *location){this->location = location;};	
};
#endif