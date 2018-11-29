#include "Grass.hpp"

Grass::Grass(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(GRASS);
	setMonsters(nullptr);
}

Grass::~Grass(){}