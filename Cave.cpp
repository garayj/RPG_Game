#include "Cave.hpp"

Cave::Cave(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(CAVE);
}


Cave::~Cave(){}