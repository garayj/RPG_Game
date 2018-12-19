/**************************************************************************************************
** Author: Jose Garay
** Date: 11/26/2018
** Description: Interface for the Map class. The Map class simulates a Map of the entire world that
this game is set in. Holds spaces of all types and the board is randomized every playthrough. Each
space is stitched together and the user can have a visual representation of the board printed to 
the screen.
**************************************************************************************************/
#ifndef MAP_HPP
#define MAP_HPP 
#include "Space.hpp"
#include "Team.hpp"
class Map
{
private:
	int row;
	int col;
	Space ***board;
	Team *heroes;

	//Randomly adds spaces to the board. Takes in an integer that acts as a counter for the amount 
	//of spaces to be added.
	void addSpace(int, spaceType);
	
	//Links the entire board together.
	void connect(int,int);
public:

	//Getter Functions for the Map class.
	Space*** getBoard(){return board;};
	Team* getHeroes(){return heroes;};
	int getRow(){return row;};
	int getCol(){return col;};


	//Setter Functions for the Map class.
	void setHeroes(Team *heroes){this->heroes = heroes;};
	void setBoard(Space ***board){this->board = board;};
	void setRow(int row){this->row = row;};
	void setCol(int col){this->col = col;}	;

	//Constructor for the Map class.
	Map();
	//Deconstructor for the Map class.
	~Map();
	//Prints a visual representation of the Map to the console.
	void printMap();


};
#endif