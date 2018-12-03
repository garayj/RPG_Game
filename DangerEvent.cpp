#include "DangerEvent.hpp"


#include "WhiteMage.hpp"
#include "BlackMage.hpp"
#include "quickSort.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using std::setw;
using std::cout;
using std::endl;



void DangerEvent::encounter(){
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

bool DangerEvent::useMagic(Character *magicUser){
	int monster;
	int hero;
	int selection;
	switch(magicUser->getCharacterClass()){
		case BLACK_MAGE:
			cout << "Would you like to use Magic Missle?\n" 
					"1.) Yes\n"
					"0.) No\n";
			selection = getMenu()->checkInputInt("Make a selection:", 0 , 1);	
			if(selection){
				if(dynamic_cast<BlackMage*>(magicUser)->getMana() >= 5){

					displayMonsters();
					cout << "\nWhich monster would you like to cast Magic Missle on?\n"
					"Select 0 to go back.\n\n";

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
					cout << "Black Mage used Magic Missle!\n"
							"It's super effective!\n"
							"Black Mage attacked for " << attack << "damage!\n";

					getSpace()->getMonsters()[monster]->defend(attack);

					//The case that the monster dies to the attack.
					if(getSpace()->getMonsters()[monster]->getHealth() <= 0 ){
						monsterDies(getSpace()->getMonsters()[monster]);
						std::cout << getSpace()->getMonsters()[monster]->getCharacterClassString() << " has fallen!" << std::endl;
					return false;
					}
				}

				else{
					cout << "You do not have enough mana to cast that!" << endl;
					return true;
				}
			}
			else{
				return true;
			}
			break;
		case WHITE_MAGE:
			//select a spell to cast
			cout << "What healing spell would you like to cast?\n"
					"1.) Healing Touch\n"
					"2.) Healing Aura\n"
					"0.) Return\n";

			selection = getMenu()->checkInputInt("Select an option on the menu", 0, 2);
			//switch depending on the spell
			switch(selection){
				//The case that you want to heal one hero.
				case 1:
					if(dynamic_cast<WhiteMage*>(magicUser)->getMana() > 0){

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
					//heal all heroes.
					if(dynamic_cast<WhiteMage*>(magicUser)->getMana() > 0){
						dynamic_cast<WhiteMage*>(magicUser)->healParty(getHeroes());
						return false;
					}
					else{
						cout << "You do not have enough mana to cast that." << endl;
						return true;
					}
					break;
				case 0:
					return true;
					break;
			}	
			break;
	}
}

void DangerEvent::monsterAttacks(Character *fighter){
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
}

bool DangerEvent::nonMagicUserMove(Character *hero){
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

bool DangerEvent::heroAttacking(Character *fighter){
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

bool DangerEvent::areMonstersAlive(){
	for(int n = 0; n < getSpace()->getMonsterCount(); n++){
		if(getSpace()->getMonsters()[n]->getIsAlive()){
			return getSpace()->getMonsters()[n]->getIsAlive();
		}
	}
	return false;
}
void DangerEvent::monsterDies(Character* monster){
	monster->setHealth(0);
	monster->setIsAlive(false);
}

void DangerEvent::heroDies(Character *hero){
	hero->setHealth(0);
	hero->setIsAlive(false);
}