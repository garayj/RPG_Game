/**************************************************************************************************
** Author: Jose Garay
** Date: 11/2/2018
** Description: Interface file for the Game Class. The Game Class organizes and conducts all the 
phases of the game.
**************************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP 
#include "Character.hpp"
#include "Team.hpp"
#include "Menu.hpp"
#include <string>


class Game{
private:
   bool isRunning;

   Menu menu;
   Map map;
   Team *heroes;
/**************************************************************************************************
** Description: The startMenu method starts the game or exits.
**************************************************************************************************/
   void startMenu();
/**************************************************************************************************
** Description: Organizes the setup of the game. Collects information from the user for the game to
be initialized.
**************************************************************************************************/
   void setup(); 
/**************************************************************************************************
** Description: End of the game. Prompts user to play the game again or exit. Cleans up memory.
**************************************************************************************************/
   void end();
/**************************************************************************************************
** Description: The main portion of the game. calls the fight function and keeps track of rounds. 
**************************************************************************************************/
   void gameplay();

/**************************************************************************************************
** Description: Setter Function. Takes a boolean as input and sets the isRunning data member.
**************************************************************************************************/
	void setIsRunning(bool isRunning){this->isRunning = isRunning;};

/**************************************************************************************************
** Description: Takes an integer as input and returns a Character pointer. The characterSelection
method returns one of the five hero characters to add to the Queue in the createTeam method.
**************************************************************************************************/
   Character* characterSelection(int);
/**************************************************************************************************
** Description: Method takes no arguments and returns nothing. Displays the teams rosters to the 
console if there are any heros.
**************************************************************************************************/
   void displayTeams();
/**************************************************************************************************
** Description: Method takes a Team pointer as an argument and returns nothing. The move Method 
moves the team into another space if the space is on the board.
**************************************************************************************************/
   void move(Team*);
public:

/**************************************************************************************************
** Description: Constructor for the Game Class.
**************************************************************************************************/
	Game();
/**************************************************************************************************
** Description: Deconstructor for the Game Class.
**************************************************************************************************/
	~Game();
/**************************************************************************************************
** Description: Public Function. Excutes a series of functions that is the game.
**************************************************************************************************/
	void run();

};
#endif