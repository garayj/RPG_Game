/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the Game Class. The Game Class organizes and conducts all the 
** phases of the game.
**************************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP 
#include "Character.hpp"
#include "Team.hpp"
#include "Map.hpp"
#include "Menu.hpp"
#include "Event.hpp"
#include <string>
#include <vector>

using std::vector;


class Game{
private:
   int timer;
   bool isRunning;
   bool won;
   Menu menu;
   Map map;
   Team *heroes;
   Event *spaceEvent;



/**************************************************************************************************
** Description: Checks to see if the player has all the four keys to win the game! Sets the won
** bool.
**************************************************************************************************/
   void fourKeys();

/**************************************************************************************************
** Description: Checks to see if any member of the team has health. Return true if one character 
has health above 0 and false if they are all dead.
**************************************************************************************************/
   bool checkTeamHealth();

/**************************************************************************************************
** Description: My probably not the best way to clear the screen.
**************************************************************************************************/
   void clearScreen();

/**************************************************************************************************
** Description: The check team method checks to see if the party is alive. Sets the isRunning data
** member to false if the party is dead.
**************************************************************************************************/
   void checkTeam();

/**************************************************************************************************
** Description: The event method is responsible for handling the events that occur on the field.
**************************************************************************************************/
   void event();

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
   void gameCycle();

/**************************************************************************************************
** Description: While the game is running, the timer is less than 30 and tthe user has not won, the 
** game will continue. The format of the game is the hero stats are printed to the screen, the map 
** is printed, the heroes move the screen is cleared and an event occurs. If the game is still 
** running after the event, the user is prompted to continue. 
**************************************************************************************************/
   void play();

   
/**************************************************************************************************
** Description: Setter Function. Takes a boolean as input and sets the isRunning data member.
**************************************************************************************************/
	void setIsRunning(bool isRunning){this->isRunning = isRunning;};

/**************************************************************************************************
** Description: Takes an integer as input and returns a Character pointer. The characterSelection
** method returns one of the five hero characters to add to the Queue in the createTeam method.
**************************************************************************************************/
   Character* characterSelection(int);

/**************************************************************************************************
** Description: Method takes a Team pointer as an argument and returns nothing. The move Method 
** moves the team into another space if the space is on the board.
**************************************************************************************************/
   void move(Team*);

/**************************************************************************************************
** Description: Getter Function. Returns the heroes data member.
**************************************************************************************************/
   Team* getTeam(){return heroes;};

/**************************************************************************************************
** Description: Setter Function. Sets the heroes data member.
**************************************************************************************************/
   void setTeam(Team* heroes){this->heroes = heroes;};






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