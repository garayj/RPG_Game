#ifndef DANGER_EVENT_STRINGS_HPP
#define DANGER_EVENT_STRINGS_HPP
#include <string> 
using std::string;

const string BLACK_MAGE_MENU = "Would you like to use Magic Missle? Costs 1 Mana.\n"	
									"1.) Yes\n"
									"0.) No\n";

const string WHITE_MAGE_MENU = "What healing spell would you like to cast?\n"
								"1.) Healing Touch - Costs 1 Mana and heals one Hero\n"
								"2.) Healing Aura - Costs 5 Mana and heals all Heroes\n"
								"0.) Return\n";

const string MAGIC_MISSLE_SELECT = "\nWhich monster would you like to cast Magic Missle on?\n"
									"Select 0 to go back.\n\n";

const string SUPER_EFFECTIVE ="Black Mage used Magic Missle!\n"
								"It's super effective!\n"
								"Black Mage attacked for ";

const string FIGHT_ORDER_HEADER = "Fighting order:\n\n";

const string CONTINUE = "\nPress enter to continue.\n";

const string SELECT_OPTION = "Select a menu option";

const string MONSTER_SELECT = "\nWhich monster would you like to attack?\nPress 0 to go back\n";

const string DEAD_MONSTER = "That monster is already dead! Another!\n\n";

const string NOT_ENOUGH_MANA = "You do not have enough mana to cast that.\n";

const string HEALING_TOUCH_MENU = "\nWhich hero would you like to heal?\n"
									"Select 0 to go back.\n\n";
const string ERROR_DOWNED_HERO = "That hero is downed! Cannot heal a downed hero. Pick another!\n\n\n";
#endif