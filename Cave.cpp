#include "Cave.hpp"

Cave::Cave(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setType(CAVE);
	setMonsters(nullptr);
}


Cave::~Cave(){}