#include "Grass.hpp"

Grass::Grass(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setType(GRASS);
	setMonsters(nullptr);
}

Grass::~Grass(){}