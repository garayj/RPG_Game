/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Header file for all the strings within the main Game portion of the game. 
**************************************************************************************************/
#ifndef MENU_STRINGS_HPP
#define MENU_STRINGS_HPP 
#include <string>

using std::string;

const string DIED = "\nYou died!\nGoodbye\n\n";

const string ERROR = "Error! Please select one of the options below:\n";

const string MAIN_MENU = "Would you like to play Hero Quest?\n"
						"1. Yes\n"
						"0. No\n";

const string TEAM_CREATION_HEADER= "Select your team!\n";

const string CHARACTER_SELECTION_MENU = "What Hero would you like to add you your team?\n\n"
										"1. Paladin: Tanky and strong. Not terribly fast though.\n"
										"2. Ranger: Quick and nimble but to move so quick, a ranger can't have much armor.\n"
										"3. Black Mage: The ultimate glass canon. Very powerful, but also very fragile.\n"
										"4. White Mage: The real MVP. Healer for the group.\n"
										"5. Rogue: Who needs to defend when you're this fast.\n"
										"6. Warrior Gnome: Best gnome.\n";

const string CHARACTER_NAME_MENU = "What would you like to name this hero?\n";


const string ERROR_CHARACTER_NAME_MENU = "Oops! They have to have a legendary name.\n" 
											"What would you like to name this hero?\n";

const string CONTINUE = "Would you like to continue?\n"
						"1: Yes\n"
						"0: Exit Game\n";

const string MOVEMENT_PROMPT = "Select a direction to move using wasd.\n"
								"w: Up\n"
								"a: Left\n"
								"s: Down\n"
								"d: Right\n";

const string FALL_OFF_MAP = "If you go that way, you'll fall off the world!\nTry again";

const string WRONG_CHAR = "That isn't a direction. It's something. Maybe a direction in another language. Try one of the following:\n"
						"w a s d\n";
const string TOO_LONG = "You said a whole bunch of not a direction. Try one of the following:\nw a s d\n";

const string THIS_IS_YOUR_TEAM = "This is your team:";

const string LOST_TIMER = "You took too much time! The King couldn't wait and decided to lop off your heads instead.\n"
							"Better luck next time!\n";

const string WON = "Sweet! You won! The King has access to his dresser, shoe collection, desk file, and gym locker.\n"
					"As a reward he gives you a high five.\n"
					"Good job!\n\n";

const string WELCOME = "Welcome to my game!\n"
						"The King has lost his four keys and it's up to you to get them back.\n"
						"The keys can be found in the dungeons.\n"
						"You have 30 days to get all the keys. After every event is the close of the day.\n"
						"Villages and Grasslands are safe zones.\n"
						"Tips: Buy and equip weapons and use defense potions\n"
						"Phoenix Downs are the only way to revive a Character that is downed.\n"
						"Black Mage's magic always hits.\n"
						"Dungeons are pretty hard so at least have weapons on each one of your heroes before attempting.\n"
						"Characters have two slots for any combination of weapons or shield\n"
						"My girlfriend was frustrated that she couldn't beat this game so this is why these tips are here.\n";


						
const string PRESS = "Press enter to continue.\n";

#endif