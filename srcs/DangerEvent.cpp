/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: The DangerEvent class inherits from the Event class. The DangerEvent class is an 
Event that happens in a dangerous area such as in the Swamps, Caves or Dungeons. The DangerEvent
class holds the fighting events that will occur. Characters are transferred into a vector and sorted
by their speed attribute. Then, one by one they attack. Monsters attack alive heros at random while 
the user can choose which monster to attack that is alive.
**************************************************************************************************/
#include "DangerEvent.hpp"

#include "WhiteMage.hpp"
#include "BlackMage.hpp"
#include "quickSort.hpp"
#include "dangerEventStrings.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using std::setw;
using std::cout;
using std::endl;

DangerEvent::DangerEvent(){
}
DangerEvent::~DangerEvent(){
}

void DangerEvent::encounter(){
	vector<Character*>allFighters;
	vector<Character*>temp;

	addFightersToVector(&allFighters);

	//Sort the vector using the a modified quicksort algorithm I used in Lab 8.
	//Sorts the characters by Speed rating from low to high.
	quickSort(&allFighters, 0, allFighters.size() - 1);

	//Loop the fight sequence until one team wins.
	while(areMonstersAlive() && getHeroes()->getIsTeamAlive()){
		fight(allFighters);
	}
}

void DangerEvent::fight(vector<Character*>temp){
	Character *fighter;

	//Loop until all the characters in the vector have been popped off.
	while(temp.size() != 0 && areMonstersAlive() && getHeroes()->getIsTeamAlive()){

		//print a list of all fighters that are still in combat to the console.
		printFightOrder(temp);

		//Clear the screen
		clearScreen();

		//Select the character with the current fastest speed rating.
		fighter = temp.back();

		//Check if the fighter object is pointing to something and if it is, checks to see if it is alive.
		//If either condition is true, remove the last character until one that is alive is found.
		while(temp.size() > 0  && (fighter == nullptr || !fighter->getIsAlive())){
			temp.pop_back();
			if(temp.size() != 0){
				fighter = temp.back();
			}
		}
		//fork between events of the 
		if(temp.size() > 0){
			fork(fighter, &temp);
		}
	}
}

void DangerEvent::fork(Character *fighter, vector<Character*> *temp){
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
	(*temp).pop_back();
}


void DangerEvent::clearScreen(){
	for(int n = 0; n < 1000; n++){
		cout << endl;
	}
}

void DangerEvent::printFightOrder(vector<Character*> temp){
	int count = 1;	
	string holder;

	cout << "Fighting order:\n\n";

	//The Characters are ordered from the slowest at index 0 and fastest at index temp.size()-1
	for(int n = temp.size() - 1; n >= 0; n--){
		if(temp.at(n)->getIsAlive()){
			cout << count << ".) " << temp.at(n)->getCharacterClassString() << endl;
			count++;
		}
	}

	cout << endl
		<< "Press enter to continue." 
		<< endl;

	getline(std::cin, holder);
}

bool DangerEvent::useMagic(Character *magicUser){
	int monster;
	int hero;
	int selection;
	switch(magicUser->getCharacterClass()){
		case BLACK_MAGE:
			return blackMageAttack(magicUser);
			break;
		case WHITE_MAGE:
			//select a spell to cast
			cout << "What healing spell would you like to cast?\n"
					"1.) Healing Touch - Costs 1 Mana and heals one Hero\n"
					"2.) Healing Aura - Costs 5 Mana and heals all Heroes\n"
					"0.) Return\n";

			selection = getMenu()->checkInputInt("Select an option on the menu", 0, 2);
			//switch depending on the spell
			switch(selection){
				//The case that you want to heal one hero.
				case 1:
					//case Healing Touch if there is mana available.
					if(dynamic_cast<WhiteMage*>(magicUser)->getMana() > 0){

						//Select a hero.	
						getHeroes()->teamStats();
						cout << "\nWhich hero would you like to heal?\n"
						"Select 0 to go back.\n\n";

						hero = getMenu()->checkInputInt("Select a menu option.\n", 0, getHeroes()->getTeamSize());

						if(hero == 0){
							return true;
						}
						while(!getHeroes()->getCharacters()[hero - 1]->getIsAlive()){
							cout << "That hero is downed! Cannot heal a downed hero. Pick another!\n\n";
							getHeroes()->teamStats();
							cout << endl;

							hero = getMenu()->checkInputInt("Select a hero on the menu.\n", 0, getHeroes()->getTeamSize());

							if(hero == 0){
								return true;
							}
						}

						hero--;
						dynamic_cast<WhiteMage*>(magicUser)->healOne(getHeroes()->getCharacters()[hero]);
						return false;
					}
					else{
						cout << "You don't have enough Mana!" << endl;
						return true;
					}

					break;
				case 2:
					//heal all heroes if the mana is available.
					if(dynamic_cast<WhiteMage*>(magicUser)->getMana() > 0){
						dynamic_cast<WhiteMage*>(magicUser)->healParty(getHeroes());
						return false;
					}
					else{
						cout << "You do not have enough mana to cast that." << endl;
						return true;
					}
					break;
				//The case the the user wants to just go back.
				case 0:
					return true;
					break;
			}	
			break;
	}
	return false;
}

bool DangerEvent::blackMageAttack(Character *magicUser){
	int monster;

	getMenu()->printMenu(BLACK_MAGE_MENU);
	int selection = getMenu()->checkInputInt("Make a selection:", 0 , 1);	
	if(selection){
		if(dynamic_cast<BlackMage*>(magicUser)->getMana() > 0){

			displayMonsters();
			getMenu()->printMenu(MAGIC_MISSLE_SELECT);

			monster = getMenu()->checkInputInt("Select a menu option.\n", 0, getSpace()->getMonsterCount());

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

			int attack = dynamic_cast<BlackMage*>(magicUser)->magicMissle();	
			getMenu()->printMenu(SUPER_EFFECTIVE + std::to_string(attack) + "damage\n");
			getSpace()->getMonsters()[monster]->defend(attack);

			//The case that the monster dies to the attack.
			if(getSpace()->getMonsters()[monster]->getHealth() <= 0 ){
				characterDies(getSpace()->getMonsters()[monster]);
				std::cout << getSpace()->getMonsters()[monster]->getCharacterClassString() << " has fallen!" << std::endl;
			return false;
			}
			return false;
		}

		else{
			cout << "You do not have enough mana to cast that!" << endl;
			return true;
		}
	}
	else{
		return true;
	}
}

void DangerEvent::monsterAttacks(Character *fighter){
	//Select an index at random until a hero that is alive is chosen.
	int randomHero = selectHero();

	//The monster attacks. If the heroes speed happens to be higher than a random roll, he dodges and takes no damage.
	if(getHeroes()->getCharacters()[randomHero]->getSpeed() > rand() % 12 + 1){
		std::cout << getHeroes()->getCharacters()[randomHero]->getName() << " the " << getHeroes()->getCharacters()[randomHero]->getCharacterClassString() << " dodged the attack." << std::endl;
	}
	else{
		monsterDamages(fighter, randomHero);
	}
}

void DangerEvent::monsterDamages(Character *fighter, int randomHero){
	int damage = fighter->attack();
	cout << fighter->getCharacterClassString() << " is attacks for " << damage << " points." << endl;

	getHeroes()->getCharacters()[randomHero]->defend(damage);

	//The case that the hero dies to the attack.
	if(getHeroes()->getCharacters()[randomHero]->getHealth() <= 0 ){
		characterDies(getHeroes()->getCharacters()[randomHero]);
		std::cout << getHeroes()->getCharacters()[randomHero]->getName() << " the " << getHeroes()->getCharacters()[randomHero]->getCharacterClassString() << " has fallen!" << std::endl;
		getHeroes()->teamAliveStatus();
	}
}

int DangerEvent::selectHero(){
	int randomHero = rand() % getHeroes()->getTeamSize();
	while(!getHeroes()->getCharacters()[randomHero]->getIsAlive()){
		randomHero = rand() % getHeroes()->getTeamSize();
	}
	return randomHero;
}

bool DangerEvent::magicUserMove(Character* hero){
	cout << "What would you like to to?\n"
			"1.) Attack\n"
			"2.) Use Item\n"
			"3.) Use Magic\n";
	int selection = getMenu()->checkInputInt("Error!\nMake a selection that's on the screen", 1, 3);
	if(selection == 1){
		return heroAttacking(hero);
	}
	else if(selection == 2){
		if(inventoryAction()){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return useMagic(hero);
	}
}

void DangerEvent::heroAttacks(Character *fighter){
	//Display who is attacking.
	std::cout << endl;
	std::cout << fighter->getName() << " the " << fighter->getCharacterClassString() << "'s turn!" << endl << endl;
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
}

bool DangerEvent::nonMagicUserMove(Character *hero){
	cout << "What would you like to to?\n"
			"1.) Attack\n"
			"2.) Use Item\n";
	int selection = getMenu()->checkInputInt("Error!\nMake a selection that's on the screen", 1, 2);
	blankScreen();
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

void DangerEvent::blankScreen(){
	for(int n = 0; n < 1000; n++){
		cout << endl;
	}
}

bool DangerEvent::heroAttacking(Character *fighter){
	displayMonsters();
	int damage;

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
		damage = fighter->attack();
		cout << fighter->getName() << " the " << fighter->getCharacterClassString() << " is attacking for " << damage << " points." << endl;
		getSpace()->getMonsters()[monster]->defend(damage);

		//The case that the monster dies to the attack.
		if(getSpace()->getMonsters()[monster]->getHealth() <= 0 ){
			characterDies(getSpace()->getMonsters()[monster]);
			std::cout << getSpace()->getMonsters()[monster]->getCharacterClassString() << " has fallen!" << std::endl;
		}
		return false;
	}

}

void DangerEvent::addFightersToVector(vector<Character*>*allFighters){

	//Add heroes to a vector.
	for(int n = 0; n < getHeroes()->getTeamSize(); n++){
		allFighters->push_back(getHeroes()->getCharacters()[n]);
	}
	//Add monsters to the vector.
	for(int n = 0; n < getSpace()->getMonsterCount(); n++){
		allFighters->push_back(getSpace()->getMonsters()[n]);
	}
}

void DangerEvent::displayMonsters(){
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
		cout << setw(12); if(getSpace()->getMonsters()[n -1]->getIsAlive()){
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

bool DangerEvent::areMonstersAlive(){
	for(int n = 0; n < getSpace()->getMonsterCount(); n++){
		if(getSpace()->getMonsters()[n]->getIsAlive()){
			return getSpace()->getMonsters()[n]->getIsAlive();
		}
	}
	return false;
}

void DangerEvent::characterDies(Character *hero){
	hero->setHealth(0);
	hero->setIsAlive(false);
}