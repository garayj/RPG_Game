#include "Swamp.hpp"

Swamp::Swamp(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(SWAMP);
	setMonsters(nullptr);
}

Swamp::~Swamp(){}