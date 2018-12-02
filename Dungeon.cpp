#include "Dungeon.hpp"

Dungeon::Dungeon(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(DUNGEON);
}
	
Dungeon::~Dungeon(){}