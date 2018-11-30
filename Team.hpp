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
	int inventorySize;
	Character **characters;
	Space *location;
	Item **inventory;
public:
	Team(int);
	~Team();





	//Getter Functions for the Team class data members
	int getTeamSize(){return teamSize;};
	int getInventorySize(){return inventorySize;};
	Character** getCharacters(){return characters;};
	Space* getLocation(){return location;};
	bool getIsTeamAlive(){return isTeamAlive;};
	Item** getInventory(){return inventory;};





	//Setter Functions for the Team class data members
	void setTeamSize(int teamSize){this->teamSize = teamSize;};
	void setInventorySize(int inventorySize){this->inventorySize = inventorySize;};
	void setCharacters(Character **characters){this->characters = characters;};
	void setLocation(Space *location){this->location = location;};	
	void setIsTeamAlive(bool isTeamAlive){this->isTeamAlive = isTeamAlive;};
	void setInventory(Item ** inventory){ this->inventory = inventory;};




	//Checks if the team any Character in the team is still alive.
	bool teamAliveStatus();
	//Prints out all the characters in the Team.
	void printCharacters();
	//Add item to inventory.
	void addItemToInventory(Item*);
	//Check if the inventory is full
	bool isInventoryEmpty();
	void removeItemFromInventory(int);
};
#endif