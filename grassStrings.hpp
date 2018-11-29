/**************************************************************************************************
** Author: Jose Garay
** Date: 11/26/2018
** Description: This Header file holds all the menus for the events that occur on the grasslands.
**************************************************************************************************/
#ifndef GRASS_MENU_HPP
#define GRASS_MENU_HPP 
#include <string>
using std::string;

const string MAIN_MENU = "Ahhh. The good ol' grasslands. Ain't no monsters here.\n"
						"1. Look at inventory.\n"
						"2. Camp. Party rests and 5 points of health and mana are restored.\n"
						"3. Continue on the Path.\n"
						"0. Quit Game.\n";

const string ERROR_MENU = "Oops. Select one of the options below:\n"
						"1. Look at inventory.\n"
						"2. Camp. Party rests and 5 points of health and mana are restored.\n"
						"3. Continue on the Path.\n"
						"0. Quit Game.\n";

const string QUIT = "Aw well. It was fun while it lasted. At least I hope it was.\n\n";

const string REST = "The group settles in for the night.\n"
					"Fire, food and drinks. The team goes to sleep after a long day.\n\n";

const string CONTINUE = "Why wait around while there's still the world to save?\n"
						"The heroes pack up and head out\n";
#endif