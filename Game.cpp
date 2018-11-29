/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Implementation file for the Game Class. The Game Class organizes and conducts all the 
phases of the game.
**************************************************************************************************/
#include "Game.hpp"

#include "Paladin.hpp"
#include "Ranger.hpp"
#include "Rogue.hpp"
#include "BlackMage.hpp"
#include "WhiteMage.hpp"
#include "WarriorGnome.hpp"

#include "CaveEvent.hpp"
#include "GrassEvent.hpp"
#include "DungeonEvent.hpp"
#include "ForestEvent.hpp"
#include "SwampEvent.hpp"
#include "VillageEvent.hpp"

#include "menuStrings.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>

using std::streamsize;
using std::numeric_limits;
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;

Game::Game(){
}

Game::~Game(){
}



void Game::run(){
	//Display start menu and if isRunning is true, runs the game.
	startMenu();
	while(isRunning){
		setup();
		gameplay();
		end();
	}
}

void Game::startMenu(){	
	menu.addMenuLine(HALFLIFE);
	menu.printMenu();
	int halflife = menu.checkInputInt(ERROR + HALFLIFE, 0 ,1);
	menu.clear();

	menu.addMenuLine(SNARK + MAIN_MENU);
	menu.printMenu();
	setIsRunning(menu.checkInputInt(ERROR + MAIN_MENU, 0, 1));	
	menu.clear();
}

void Game::setup(){
	int selection;
	heroes = new Team(3);

	menu.addMenuLine(TEAM_CREATION_HEADER);
	menu.printMenu();

	//Team selection
	for(int n = 0; n < heroes->getTeamSize(); n++){
		menu.clear();
		menu.addMenuLine(CHARACTER_SELECTION_MENU);
		menu.printMenu();
		selection  = menu.checkInputInt(ERROR + CHARACTER_SELECTION_MENU, 1, 6);
		heroes->getCharacters()[n] = characterSelection(selection);
	}

	//Print out team.
	cout << "This is your team" << endl;
	for(int n = 0; n < heroes->getTeamSize(); n++){
		cout << n +1 << ". " << heroes->getCharacters()[n]->getCharacterClassString() << endl;
	}
	map.setHeroes(heroes);
	heroes->setLocation(map.getBoard()[0][0]);
}


Character* Game::characterSelection(int selection){
	Character *newCharacter;
	switch(selection){
		case 1:
			newCharacter = new Paladin();
			break;
		case 2:
			newCharacter = new Ranger();
			break;
		case 3:
			newCharacter = new BlackMage();
			break;
		case 4:
			newCharacter = new WhiteMage();
			break;
		case 5:
			newCharacter = new Rogue();
			break;
		case 6:
			newCharacter = new WarriorGnome();
			break;
	}
	return newCharacter;
}

void Game::gameplay(){
	map.printMap();
	while(isRunning){
		move(heroes);
		event();
		if(isRunning){
			map.printMap();
			cout << "Would you like to continue?" << endl;
			setIsRunning(menu.checkInputInt("Enter 1 or 0", 0, 1));	
		}
	}	
}

// void Game::fight(Character *player1, Character *player2){
// }

void Game::end(){
	delete heroes;
}

void Game::displayTeams(){
}

void Game::move(Team *team){
	string input;
	int direction;
	bool isValidMove = true, isInArray = false;
	vector<int> numArray = {97, 100, 115, 119};

	cout << "Enter wasd" << endl;


	getline(cin, input);

	while(isValidMove){

		if(input.length() == 1){
			direction = input[0];
			isInArray = false;
			for(int n = 0; n < numArray.size(); n++){
				if(direction == numArray[n]){
					isInArray = true;
				}
			}
			if(isInArray){
				switch(direction){
					case 119:
						if(team->getLocation()->getUp() != nullptr){
							team->setLocation(team->getLocation()->getUp());
							isValidMove = false;
						}
						else{
							cout << "If you go that way, you'll fall off the world!\nTry again" << endl;
							getline(cin, input);
						}
						break;
					case 97:
						if(team->getLocation()->getLeft() != nullptr){
							team->setLocation(team->getLocation()->getLeft());
							isValidMove = false;
						}
						else{
							cout << "If you go that way, you'll fall off the world!\nTry again" << endl;
							getline(cin, input);
						}
						break;
					case 115:
						if(team->getLocation()->getDown() != nullptr){
							team->setLocation(team->getLocation()->getDown());
							isValidMove = false;
						}
						else{
							cout << "If you go that way, you'll fall off the world!\nTry again" << endl;
							getline(cin, input);
						}
						break;
					case 100:
						if(team->getLocation()->getRight() != nullptr){
							team->setLocation(team->getLocation()->getRight());
							isValidMove = false;
						}

						else{
							cout << "If you go that way, you'll fall off the world!\nTry again" << endl;
							getline(cin, input);
						}
						break;
				}
			}
			else{
				cout << "That isn't a direction. It's something. Maybe a direction in another language. Try one of the following:\n"
						"w a s d" << endl;
				getline(cin, input);
			}
		}	
		else{
			cout << "You said a whole bunch of not a direction. Try one of the following:\nw a s d\n";
			getline(cin,input);
		}

	}

}

void Game::event(){
	switch(heroes->getLocation()->getSpaceType()){
		case GRASS:
			spaceEvent = new GrassEvent(heroes);
			delete spaceEvent;
			checkTeam();
			break;
		case FOREST:
			spaceEvent = new ForestEvent(heroes);
			delete spaceEvent;
			checkTeam();
			break;
		case CAVE:
			spaceEvent = new CaveEvent(heroes);
			delete spaceEvent;
			checkTeam();
			break;
		case VILLAGE:
			spaceEvent = new VillageEvent(heroes);
			delete spaceEvent;
			checkTeam();
			break;
		case DUNGEON:
			spaceEvent = new DungeonEvent(heroes);
			delete spaceEvent;
			checkTeam();
			break;
		case SWAMP:
			spaceEvent = new SwampEvent(heroes);
			delete spaceEvent;
			checkTeam();
			break;
	}
}

void Game::checkTeam(){
	if(!heroes->getIsTeamAlive()){
		setIsRunning(false);
	}
}

