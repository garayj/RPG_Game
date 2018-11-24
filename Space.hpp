#ifndef SPACE_HPP
#define SPACE_HPP 
#include "Character.hpp"

enum spaceType {GRASS, FOREST, CAVE, VILLAGE, DUNGEON, SWAMP};
class Space
{
protected:
	Space *up;
	Space *down;
	Space *left;
	Space *right;
	spaceType type;

	Character **monsters;

public:
	Space();
	virtual ~Space()=0;
	Space* getUp(){return up;};
	Space* getDown(){return down;};
	Space* getLeft(){return left;};
	Space* getRight(){return right;};
	spaceType getType(){return type;};
	Character **getMonsters(){return monsters;};


	void setUp(Space* up){this->up = up;};
	void setDown(Space* down){this->down = down;};
	void setLeft(Space* left){this->left = left;};
	void setRight(Space* right){this->right = right;};
	void setType(spaceType type){this->type = type;};
	void setMonsters(Character **monsters){this->monsters = monsters;};
};
#endif