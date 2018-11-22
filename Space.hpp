#ifndef SPACE_HPP
#define SPACE_HPP 

enum spaceType {GRASS, CAVE, LAKE, VILLAGE, CASTLE};
class Space
{
protected:
	Space *up;
	Space *down;
	Space *left;
	Space *right;
	spaceType type;


public:
	Space();
	virtual ~Space()=0;
	Space* getUp(){return up;};
	Space* getDown(){return down;};
	Space* getLeft(){return left;};
	Space* getRight(){return right;};
	spaceType getType(){return type;};

	void setUp(Space* up){this->up = up;};
	void setDown(Space* down){this->down = down;};
	void setLeft(Space* left){this->left = left;};
	void setRight(Space* right){this->right = right;};
	void setType(spaceType type){this->type = type;};
};
#endif