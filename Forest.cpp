#include "Forest.hpp"

Forest::Forest(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(FOREST); 
}

Forest::~Forest(){}