#include "Village.hpp"

Village::Village(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setType(VILLAGE);
	setMonsters(nullptr);
}

Village::~Village(){}