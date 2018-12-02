#ifndef VILLAGESTRINGS_HPP
#define VILLAGESTRINGS_HPP 
#include <string>
using std::string;

const string MAIN_MENU = "Your party walks into a village. There are merchants selling all kinds of goods.\n"
						"Lots of hustle and bustle for such a small place but at least there are no monsters here.\n\n"
						"1. Look at inventory.\n"
						"2. Sleep at the local inn. Party rests and health and mana are fully restored.\n"
						"3. Continue on the Path.\n"
						"4. Buy goods from the the Weapons \'n Stuff\n"
						"0. Quit Game.\n";

const string ERROR_MENU = "Oops. Select one of the options:\n"
						"1. Look at inventory.\n"
						"2. Camp. Party rests and 5 points of health and mana are restored.\n"
						"3. Continue on the Path.\n"
						"4. Buy goods from the the Weapons \'n Stuff\n"
						"0. Quit Game.\n";

const string QUIT = "Aw well. It was fun while it lasted. At least I hope it was.\n\n";

const string ERROR = "Ooops. Try selecting something on the screen.\n\n";

const string INVENTORY = "Here is your inventory:\n\n";

const string REST = "The group settles in for the night.\n"
					"Fire, food and drinks. The team goes to sleep after a long day.\n\n";

const string CONTINUE = "Why wait around while there's still the world to save?\n"
						"The heroes pack up and head out\n";

const string USE_ITEM = "Select the item you would like to use or select 0 to go back.\n";

const string MERCHANT = "Welcome Travelers!\n"
						"Take a look at my wares\n"
						"1: 1000G Greater Sword - Hard as a diamond, strong as a bear. This blade was made for cutting up baddies. +10 Damage(For the Paladin class)\n"
						"2: 400G Magic Shield - A little pendant that absorbs damage that you may take. +5 Armor (For any class)\n"
						"3: 2000G Battle Wand - A stick. It just looks like a stick. +15 Damage(For Black Mage only)\n"
						"4: 500G Healing Wand - A unicorn lost it's horn for this. +10 Healing(For White Mage only)\n"
						"5: 1000G Great Hammer - The perfect hammer. Made by the Dwarves of Dwarvington, +10 Damage(For Warrior Gnome class)\n"
						"6: 2000G Sharp Dagger - A knife from Target. +30 Damage (For Rogue class)\n"
						"7: 1500G Crossbow - Shoots arrows with such accuracy. Use this instead of a bow you scrub. +15 Damage(For Ranger class)\n"
						"8: 100G Health Potion - Tastes like cherries. +5 HP\n"
						"9: 1000G Phoenix Down - Pigeon feathers. Heroes are revived with full health (and mana)\n"
						"10: 1000G Defense Potion - Tastes like a castle. +5 Defense\n"
						"0: Walk away.\n";

const string INVENTORY_FULL = "You have no space in your inventory!\nFree some space if you want to buy stuff.\n\n";
#endif