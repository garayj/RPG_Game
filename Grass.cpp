#include "Grass.hpp"

Grass::Grass(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setType(GRASS);
}

Grass::~Grass(){}