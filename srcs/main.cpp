/**************************************************************************************************
** Program: Final Project - Heroes Quest
** Author: Jose Garay
** Date: 12/4/2018
** Description: Heroes Quest is a game where you create a party of 3 Heroes and try to collect 4
keys for the King. Other than Villages and Greenlands, every other space has monsters on them, with
a chance to fight them. Forests have a low chance, Swamps have a moderate chance, Caves have a high
chance, and Dungeons have a 100% chance. There are 30 days to complete this quest. If you are 
having trouble beating the game, buy the appropriate gear for your hero, and bring phoenix downs 
to the dungeons. Once you can beat one, the rest should be of comparable difficulty.
**************************************************************************************************/
#include "Game.hpp"
#include <ctime>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Game game;
	game.run();
	return 0;
}
