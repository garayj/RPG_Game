#include "GreaterSword.hpp"

GreaterSword::GreaterSword(){
	setEffect(10);
	setItemName("Greater Sword");
	setType(WEAPON);
	setDescription("A really sharp sword to poke stuff. There's a legend behind it I think. It glows green.\n");
	setItemType(EQUIPMENT);
	setClassType(PALADIN);
}
GreaterSword::~GreaterSword(){}