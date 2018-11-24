#include "Dungeon.hpp"

Dungeon::Dungeon(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setType(DUNGEON);
	setMonsters(nullptr);
}
	
Dungeon::~Dungeon(){}