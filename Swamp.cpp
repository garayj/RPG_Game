#include "Swamp.hpp"

Swamp::Swamp(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setType(SWAMP);
	setMonsters(nullptr);
}

Swamp::~Swamp(){}