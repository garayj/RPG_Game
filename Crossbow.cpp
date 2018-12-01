#include "Crossbow.hpp"

Crossbow::Crossbow(){
	setEffect(15);
	setItemName("Crossbow");
	setType(WEAPON);
	setDescription("Shoots arrows n stuff.\n");
	setItemType(EQUIPMENT);
	setClassType(RANGER);
}
Crossbow::~Crossbow(){}