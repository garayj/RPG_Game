#include "MagicShield.hpp"

MagicShield::MagicShield(){
	setEffect(5);
	setItemName("Magic Shield");
	setType(ARMOR);
	setDescription("An invisible magic shield.\n");
	setItemType(EQUIPMENT);
}
MagicShield::~MagicShield(){}