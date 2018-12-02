/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The SwapEvent Class extends the Event class and contains the events that occur on
a Swamp Space. On a Swamp Space, things are dangerous. If there are monsters alive, the user has a
small chance to sneak on by or walk into trouble. If the user has already defeated the monsters,
the user walks into no more trouble. Zombies and mud goblins live here.
**************************************************************************************************/
#include "SwampEvent.hpp"
#include "Zombie.hpp"
#include "quickSort.hpp"
#include "MudGoblin.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using std::setw;
using std::cout;
using std::endl;

SwampEvent::SwampEvent(Team *heroes, Space *swamp){

	setMenu(new Menu());
	setHeroes(heroes);
	setSpace(swamp);
	getHeroes()->getCharacters()[2]->setHealth(0);
	getHeroes()->getCharacters()[2]->setIsAlive(false);
	if(areMonstersAlive()){
		int chance = rand() %10;
		if(chance < 6){
			encounter();
		}
		else{
			std::cout << "You stay quiet and move quickly. You escape without confrontation.\n\n";
		}
	}
	else{
		std::cout << "Looks like you already beat these guys to a pulp. Lets get out of this creepy place.\n\n";
	}
	delete menu;
}

void SwampEvent::encounter(){
	string holder;
	vector<Character*>allFighters;
	vector<Character*>temp;

	addFightersToVector(&allFighters);

	//Sort the vector using the a modified quicksort algorithm I used in Lab 8.
	//Sorts the characters by Speed rating from low to high.
	quickSort(&allFighters, 0, allFighters.size() - 1);

	//Loop the fight sequence until one team wins.
	while(areMonstersAlive() && getHeroes()->getIsTeamAlive()){
		temp = allFighters;
		Character *fighter;

		//Loop until all the characters in the vector have been popped off.
		cout << endl;
		cout << "This is the fighting order:\n";
		while(temp.size() != 0 && areMonstersAlive() && getHeroes()->getIsTeamAlive()){
			for(int n = temp.size() - 1; n >= 0; n--){
				cout << temp.at(n)->getCharacterClassString() << endl;
			}
			cout << endl;
			cout << "Press enter to continue." << endl;
			getline(std::cin, holder);

			for(int n = 0; n < 1000; n++){
				cout << endl;
			}
			//Select the character with the current fastest speed rating.
			fighter = temp.back();

			//Check if the fighter object is pointing to something and if it is, checks to see if it is alive.
			if(fighter != nullptr && fighter->getIsAlive()){

				//If that character is a monster.
				if(fighter->getType() == MONSTER){
					monsterAttacks(fighter);
					cout << endl;
				}
				else{
					heroes->teamStats();
					heroAttacks(fighter);
					cout << endl;
				}
			}	
			temp.pop_back();
		}
	}

}

void SwampEvent::monsterAttacks(Character *fighter){
	int damage;
	//Select an index at random until a hero that is alive is chosen.
	int randomHero = rand() % getHeroes()->getTeamSize();
	while(!getHeroes()->getCharacters()[randomHero]->getIsAlive()){
		randomHero = rand() % getHeroes()->getTeamSize();
	}
	cout << fighter->getCharacterClassString() << " is attacking." << endl;

	//The monster attacks. If the heroes speed happens to be higher than a random roll, he dodges and takes no damage.
	if(getHeroes()->getCharacters()[randomHero]->getSpeed() > rand() % 12 + 1){
		std::cout << getHeroes()->getCharacters()[randomHero]->getName() << " the " << getHeroes()->getCharacters()[randomHero]->getCharacterClassString() << " dodged the attack." << std::endl;
	}
	else{
		damage = fighter->attack();
		cout << fighter->getCharacterClassString() << " is attacking for " << damage << " points." << endl;
		getHeroes()->getCharacters()[randomHero]->defend(damage);

		//The case that the hero dies to the attack.
		if(getHeroes()->getCharacters()[randomHero]->getHealth() <= 0 ){
			heroDies(getHeroes()->getCharacters()[randomHero]);
			std::cout << getHeroes()->getCharacters()[randomHero]->getName() << " the " << getHeroes()->getCharacters()[randomHero]->getCharacterClassString() << " has fallen!" << std::endl;
			getHeroes()->teamAliveStatus();
		}
	}
}
bool SwampEvent::magicUserMove(Character*){
	return false;
	// bool madeAction;
	// while(selection){
	// 	switch(selection){
	// 		case 1:
	// 			// heroAttack(fighter,swamp);
	// 			break;
	// 		case 2:
	// 			madeAction = inventoryAction();
	// 			break;
	// 		case 3:
	// 			switch(fighter->getCharacterClass()){
	// 				case WHITE_MAGE:
	// 					cout << "What spell would you like to cast?\n"
	// 							"1.) Healing Touch: Heals one hero for a random amount between 1 and 10. Costs 1 Mana\n"
	// 							"2.) Healing Aura: Heals the entire party for between 1 and 10 HP. Costs 5 Mana\n"
	// 							"0.) Back\n";
	// 					selection = getMenu()->checkInputInt("Selection an option above:", 1, 2);
	// 					if(selection == 1){
	// 						cout << "Who would you like to heal?" << endl << endl;
	// 						getHeroes()->teamStats();
	// 						int healCharacter = getMenu()->checkInputInt("Select a hero.", 1, getHeroes()->getTeamSize())
	// 						while(!getHeroes()->getCharacters()[healCharacter - 1]->isAlive()){
	// 							cout << "That hero is dead"
	// 						}



	// 					}
	// 					break;
	// 				case BLACK_MAGE:
	// 					break;
	// 			}

	// 			break;

	// 	}
	// }
}

void SwampEvent::heroAttacks(Character *fighter){
	//Display who is attacking.
	std::cout << fighter->getName() << " the " << fighter->getCharacterClassString() << "'s turn!" << endl;
	bool madeAction = true;
	while(madeAction){
		switch(fighter->getCharacterClass()){
			case BLACK_MAGE:
			case WHITE_MAGE:
				madeAction = magicUserMove(fighter);
				break;
			case RANGER:
			case WARRIOR_GNOME:
			case PALADIN:
			case ROGUE:
				madeAction = nonMagicUserMove(fighter);
				break;
		}

	}
	// if(fighter->getType() == BLACK_MAGE || fighter->getType() == WHITE_MAGE){
	// 	cout << "3.) Use Magic\n";
	// 	int selection = getMenu()->checkInputInt("Error!\nMake a selection that's on the screen", 1, 3);
	// 	isTurnt = magicUserMove(selection);
	// }


	// //Prompt the user to make an attack.
	// cout << "Who do you want to attack?" << endl << endl;
	// displayMonsters();
	// int selection = getMenu()->checkInputInt("Error select one of the numbers to the left", 1, getSpace()->getMonsterCount());
	// while(!getSpace()->getMonsters()[selection - 1]->isAlive()){
	// 	cout << "Ah, that monster is already dead!\nPick another\n";
	// 	int selection = getMenu()->checkInputInt("Error select one of the numbers to the left", 1, getSpace()->getMonsterCount());
	// }

}

bool SwampEvent::nonMagicUserMove(Character *hero){
	cout << "What would you like to to?\n"
			"1.) Attack\n"
			"2.) Use Item\n";
	int selection = getMenu()->checkInputInt("Error!\nMake a selection that's on the screen", 1, 2);
	if(selection == 1){
		return heroAttacking(hero);
	}
	else{
		if(inventoryAction()){
			return false;
		}
		else{
			return true;
		}
	}

}

bool SwampEvent::heroAttacking(Character *fighter){
	displayMonsters();

	cout << "\nWhich monster would you like to attack?\n";
	cout << "Press 0 to go back\n";

	int monster = getMenu()->checkInputInt("Select a monster on the menu.\n", 0, getSpace()->getMonsterCount());

	if(monster == 0){
		return true;
	}

	while(!getSpace()->getMonsters()[monster - 1]->getIsAlive()){
		cout << "That monster is already dead! Pick another!\n\n";
		displayMonsters();
		cout << endl;

		monster = getMenu()->checkInputInt("Select a monster on the menu.\n", 0, getSpace()->getMonsterCount());

		if(monster == 0){
			return true;
		}
	}

	monster--;

	if(getSpace()->getMonsters()[monster]->getSpeed() > rand() % 12 + 1){
		std::cout << getSpace()->getMonsters()[monster]->getCharacterClassString() << " dodged the attack." << std::endl;
		return false;
	}
	else{
		getSpace()->getMonsters()[monster]->defend(fighter->attack());

		//The case that the monster dies to the attack.
		if(getSpace()->getMonsters()[monster]->getHealth() <= 0 ){
			monsterDies(getSpace()->getMonsters()[monster]);
			std::cout << getSpace()->getMonsters()[monster]->getCharacterClassString() << " has fallen!" << std::endl;
		}
		return false;
	}

}

void SwampEvent::addFightersToVector(vector<Character*>*allFighters){

	//Add heroes to a vector.
	for(int n = 0; n < getHeroes()->getTeamSize(); n++){
		allFighters->push_back(getHeroes()->getCharacters()[n]);
	}
	//Add monsters to the vector.
	for(int n = 0; n < getSpace()->getMonsterCount(); n++){
		allFighters->push_back(getSpace()->getMonsters()[n]);
	}
}

void SwampEvent::displayMonsters(){
	cout << setw(4);
	cout << "#";
	cout << "|";
	cout << setw(12);
	cout << "Monster";
	cout << "|";
	cout << setw(6);
	cout << "Health";
	cout << endl;

	for(int n = 1; n <= getSpace()->getMonsterCount(); n++){
		cout << setw(4);
		cout << n;
		cout << "|";
		cout << setw(12);
		if(getSpace()->getMonsters()[n -1]->getIsAlive()){
			cout << getSpace()->getMonsters()[n - 1]->getCharacterClassString();
			cout << "|";
			cout << setw(6);
			cout << getSpace()->getMonsters()[n - 1]->getHealth() << "/" << getSpace()->getMonsters()[n - 1]->getMaxHealth();
			cout << endl;
		}
		else{
			cout << "Dead\n";
		}
	}	
}

bool SwampEvent::areMonstersAlive(){
	for(int n = 0; n < getSpace()->getMonsterCount(); n++){
		if(getSpace()->getMonsters()[n]->getIsAlive()){
			return getSpace()->getMonsters()[n]->getIsAlive();
		}
	}
	return false;
}
void SwampEvent::monsterDies(Character* monster){
	monster->setHealth(0);
	monster->setIsAlive(false);
}

void SwampEvent::heroDies(Character *hero){
	hero->setHealth(0);
	hero->setIsAlive(false);
}