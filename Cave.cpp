#include "Cave.hpp"

Cave::Cave(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(CAVE);
	setMonsters(nullptr);
}


Cave::~Cave(){}