#include "Forest.hpp"

Forest::Forest(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setType(FOREST); 
	setMonsters(nullptr);
}

Forest::~Forest(){}