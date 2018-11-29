#include "Village.hpp"

Village::Village(){
	setUp(nullptr);
	setDown(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setSpaceType(VILLAGE);
 	setMonsters(nullptr);
}

Village::~Village(){}