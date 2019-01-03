/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: The Space class represents a space on the board. Each space contains four directions,
a pointer to a pointer of monsters, and a count of those monsters. The entire Map is made up of 36
spaces that the user can traverse using the w a s d keys. There is also a spaceType enum that is 
used to distingush which type of space each space is. This is an abstract class.
**************************************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP 
#include "Character.hpp"

enum spaceType {GRASS, FOREST, CAVE, VILLAGE, DUNGEON, SWAMP};
class Space
{
protected:
	int monsterCount;
	Space *up;
	Space *down;
	Space *left;
	Space *right;
	spaceType type;

	Character **monsters;

public:
	//Constructor for the Space Class.
	Space();
	//Deconstructor for the Space Class. Pure Virtual Function.
	virtual ~Space()=0;

	//Getter Functions for the protected data members of the Space Class.
	Space* getUp(){return up;};
	Space* getDown(){return down;};
	Space* getLeft(){return left;};
	Space* getRight(){return right;};
	spaceType getSpaceType(){return type;};
	Character **getMonsters(){return monsters;};
	int getMonsterCount(){return  monsterCount;};


	//Setter Functions for the protected data members of the Space Class.
	void setUp(Space* up){this->up = up;};
	void setDown(Space* down){this->down = down;};
	void setLeft(Space* left){this->left = left;};
	void setRight(Space* right){this->right = right;};
	void setSpaceType(spaceType type){this->type = type;};
	void setMonsters(Character **monsters){this->monsters = monsters;};
	void setMonsterCount(int monsterCount){this->monsterCount = monsterCount;};
};
#endif