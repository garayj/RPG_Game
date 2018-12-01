#include "HealingWand.hpp"

HealingWand::HealingWand(){
	setEffect(10);
	setItemName("Healing Wand");
	setType(WEAPON);
	setDescription("A unicorns......horn.\n");
	setItemType(EQUIPMENT);
	setClassType(WHITE_MAGE);
}
HealingWand::~HealingWand(){}