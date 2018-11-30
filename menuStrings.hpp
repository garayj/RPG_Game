#ifndef MENU_STRINGS_HPP
#define MENU_STRINGS_HPP 
#include <string>

using std::string;

const string ERROR = "Error! Please select one of the options below:\n";

const string MAIN_MENU = "Would you like to play my game instead?\n"
						"1. Yes\n"
						"0. No\n";

const string TEAM_CREATION_HEADER= "Select your team!\n";

const string CHARACTER_SELECTION_MENU = "What Hero would you like to add you your team?\n\n"
										"1. Paladin: Tanky and strong. Not terribly fast though.\n"
										"2. Ranger: Quick and nimble but to move so quick, the ranger don't have much armor.\n"
										"3. Black Mage: The ultimate glass canon. Very powerful, but also very fragile.\n"
										"4. White Mage: The real MVP.\n"
										"5. Rogue: Who needs to defend when you're this fast.\n"
										"6. Warrior Gnome: Best gnome.\n";

const string CHARACTER_NAME_MENU = "What would you like to name this hero?\n";


const string ERROR_CHARACTER_NAME_MENU = "Oops! They have to have a legendary name.\n" 
											"What would you like to name this hero?\n";
#endif