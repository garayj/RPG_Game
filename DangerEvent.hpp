#ifndef DANGER_EVENT_HPP
#define DANGER_EVENT_HPP 
#include "Event.hpp"
#include "Character.hpp"
#include <vector>
using std::vector;

class DangerEvent :public  Event
{
protected:
	//Returns a boolean if the user actually made a magic attack or not using a magical hero.
	bool useMagic(Character*);
	//Displays the monsters to the screen.
	void displayMonsters();

	//Checks to see if there are monsters alive in the space.
	bool areMonstersAlive();

	//The case that a monster dies.
	void monsterDies(Character*);
	
	//The case that a hero dies.
	void heroDies(Character*);

	//Method that simulates the encounter between the heroes and monsters on the space.
	void encounter();

	//Method that simulates a monster attacking.
	void monsterAttacks(Character *);

	//Method that simulates a hero attacking.
	void heroAttacks(Character *);

	//Method that simulates the move of one of the magic users.
	bool magicUserMove(Character*);

	//Method that simulates the move of one of the non-magic users.
	bool nonMagicUserMove(Character*);

	//Method that adds both heroes and monsters into a vector.
	void addFightersToVector(vector<Character*>*);

	//Simulates a hero attacking returns a bool on whether or not the user went through with the attack.
	bool heroAttacking(Character*);
public:
	DangerEvent();
	virtual ~DangerEvent()=0;
	
};
#endif