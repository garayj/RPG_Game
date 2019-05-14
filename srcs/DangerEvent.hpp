/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The DangerEvent class inherits from the Event class. The DangerEvent class is an 
Event that happens in a dangerous area such as in the Swamps, Caves or Dungeons. The DangerEvent
class holds the fighting events that will occur. Characters are transferred into a vector and sorted
by their speed attribute. Then, one by one they attack. Monsters attack alive heros at random while 
the user can choose which monster to attack that is alive.
**************************************************************************************************/
#ifndef DANGER_EVENT_HPP
#define DANGER_EVENT_HPP 
#include "Event.hpp"
#include "Character.hpp"
#include <vector>
using std::vector;


class DangerEvent :public  Event
{
protected:
	//Returns nothing and takes no arguements. Clears the screen of any text.
	void blankScreen();

	//Returns a boolean if the user actually made a magic attack or not using a magical hero.
	bool useMagic(Character*);

	// Returns a boolean. If the user is able to make an action, returns true. If the user does not have
	// enough mana, returns false.
	bool blackMageAction(Character *);

	// Returns a boolean. If the user is able to make an action, returns true. If the user does not have
	// enough mana, returns false.
	bool whiteMageAction(Character *);

	bool useHealingTouch(Character *);

	//Displays the monsters to the screen.
	void displayMonsters();

	//Checks to see if there are monsters alive in the space. Returns a boolean.
	bool areMonstersAlive();

	//The case that a hero dies.
	void characterDies(Character *);

	//Method that simulates the encounter between the heroes and monsters on the space.
	void encounter();

	//Method that simulates a monster attacking.
	void monsterAttacks(Character *);

	//Method that simulates a hero attacking.
	void heroAttacks(Character *);

	//Method that simulates the move of one of the magic users.
	bool magicUserMove(Character *);

	//Method that simulates the move of one of the non-magic users.
	bool nonMagicUserMove(Character *);

	//Method that adds both heroes and monsters into a vector.
	void addFightersToVector(vector<Character *>*);

	//Simulates a hero attacking returns a bool on whether or not the user went through with the attack.
	bool heroAttacking(Character *);

	//The fight method simulates the characters on a space fighting.
	void fight(vector<Character *>);

	// The printFightOrder takes a vector of character pointers and prints out the order in which the 
	// characters will fight.
	void printFightOrder(vector<Character *>);

	//Clears the console screen.
	void clearScreen();

	// The method acts as a "fork" in the road for the characters. If monsters, continue down the monster
	// path. Heroes continue down a different path. Glorified if statement quite literally.
	void fork(Character*, vector<Character *>*);

	// Randomly selects a hero for the monster to attack.
	int selectHero();

	// Monster attacks a Character. Takes a character and integer in as arguments. The Character pointer is the monster
	// that is dealing damage and the integer is the position in the team the monster will hit.	
	void monsterDamages(Character *, int);

	//The hero dodges the attack. Takes an integer as an argument and 
	void heroDodges(int);


public:
	//Constructor for the DangerEvent Class.
	DangerEvent();
	//Deconstructor for the DangerEvent Class. Pure Virtual Function.
	virtual ~DangerEvent()=0;
	
};
#endif