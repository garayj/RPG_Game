/**************************************************************************************************
** Author: Jose Garay
** Date: 12/4/2018
** Description: Interface for the BattleWand class. The Battle Wand is an Item is a piece of 
Equipment. BattleWant inherits from the Equipment class. Only the BlackMage class can use the Battle
Wand. When equip, the Battle Wand gives a +15 damage to the Black Mages attack.
**************************************************************************************************/
#ifndef BATTLE_WAND_HPP
#define BATTLE_WAND_HPP
#include "Equipment.hpp"
class BattleWand : public Equipment
{
public:
	//Constructor for the BattleWand Class;
	BattleWand();
	//Deconstructor for the BattleWand Class;
	~BattleWand();
};
#endif