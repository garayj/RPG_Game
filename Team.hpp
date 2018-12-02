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
#include <vector>

using std::vector;

class Team
{
private:
	bool isTeamAlive;
	int teamSize;
	int inventorySize;
	Character **characters;
	Space *location;
	vector<Item*>* inventory;
	int gold;

	//Takes in an integer representing the index of the item the user would like to use.
	//Used in the inventoryMenu method only.
	bool useItem(int);

	//Takes in an integer representing the index of the item the user would like to use.
	//Used in the useItem method only.
	bool equip(int);

	//Takes in an integer representing the index of the item the user would like to use.
	//Used in the useItem method only.
	bool usePotion(int);
public:
	Team(int);
	~Team();





	//Getter Functions for the Team class data members
	int getTeamSize(){return teamSize;};
	int getInventorySize(){return inventorySize;};
	Character** getCharacters(){return characters;};
	Space* getLocation(){return location;};
	bool getIsTeamAlive(){return isTeamAlive;};
	vector<Item*>* getInventory(){return inventory;};
	int getGold(){return gold;};





	//Setter Functions for the Team class data members
	void setTeamSize(int teamSize){this->teamSize = teamSize;};
	void setInventorySize(int inventorySize){this->inventorySize = inventorySize;};
	void setCharacters(Character **characters){this->characters = characters;};
	void setLocation(Space *location){this->location = location;};	
	void setIsTeamAlive(bool isTeamAlive){this->isTeamAlive = isTeamAlive;};
	void setInventory(vector<Item*>* inventory){ this->inventory = inventory;};
	void setGold(int gold){this->gold = gold;};




	//Checks if the team any Character in the team is still alive.
	void teamAliveStatus();
	//Prints out all the characters in the Team.
	void printCharacters();
	//Add item to inventory.
	void addItemToInventory(Item*);
	//Remove an item from integerventory. Takes an integer as input and to use as an index.
	void removeItemFromInventory(int);
	//Prints out all the contents of the inventory to the console for the user.
	void printInventory();
	//Opens a menu to the user and prompts them to use items in their inventory if there are any items.
	bool inventoryMenu(int);
	//Check if the inventory is full.
	bool isInventoryFull();
	//Prints out the Character stats to the console.
	void teamStats();
};
#endif