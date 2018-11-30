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

#include "Item.hpp"

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
	timer = 0;
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
	menu.addMenuLine(MAIN_MENU);
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
		menu.clear();
		menu.addMenuLine(CHARACTER_NAME_MENU);
		menu.printMenu();
		heroes->getCharacters()[n]->setName(menu.checkInputString(ERROR_CHARACTER_NAME_MENU));
	}

	//Print out team.
	clearScreen();

	menu.clear();
	menu.addMenuLine(THIS_IS_YOUR_TEAM);
	menu.printMenu();

	heroes->printCharacters();

	//Add the Heroes to the map so the map can know the location of the heroes.
	map.setHeroes(heroes);
	//Set the heroes on the map so they can move around.
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
	while(isRunning && timer <= 30){
		move(heroes);
		clearScreen();
		event();
		if(isRunning){
			map.printMap();
			menu.clear();
			menu.addMenuLine(CONTINUE);
			menu.printMenu();
			setIsRunning(menu.checkInputInt(ERROR + CONTINUE, 0, 1));	
		}
	}	
	if(timer == 30 && won){
		menu.clear();
		menu.addMenuLine(LOST_TIMER);
		menu.printMenu();
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

	//All needed variables for the method.
	string input;
	int direction;
	bool isValidMove = true, isInArray = false;
	vector<int> numArray = {97, 100, 115, 119};

	//Print movement options menu.
	menu.clear();
	menu.addMenuLine(MOVEMENT_PROMPT);
	menu.printMenu();
	menu.clear();


	getline(cin, input);
	//Checks if the move is a valid move.
	while(isValidMove){
		//Checks if the input is just one character long.
		if(input.length() == 1){
			direction = input[0];
			isInArray = false;


			//If the input is one character long, look to see if the character is one of the ASCII 
			//values of w a s or d.
			for(int n = 0; n < numArray.size(); n++){
				if(direction == numArray[n]){
					isInArray = true;
				}
			}
			//If it is one of the values, check if that direction is a valid space and not null.
			if(isInArray){
				switch(direction){
					case 119:
						if(team->getLocation()->getUp() != nullptr){
							team->setLocation(team->getLocation()->getUp());
							isValidMove = false;
						}
						else{
							menu.addMenuLine(FALL_OFF_MAP);
							menu.printMenu();
							getline(cin, input);
						}
						break;
					case 97:
						if(team->getLocation()->getLeft() != nullptr){
							team->setLocation(team->getLocation()->getLeft());
							isValidMove = false;
						}
						else{
							menu.addMenuLine(FALL_OFF_MAP);
							menu.printMenu();
							getline(cin, input);
						}
						break;
					case 115:
						if(team->getLocation()->getDown() != nullptr){
							team->setLocation(team->getLocation()->getDown());
							isValidMove = false;
						}
						else{
							menu.addMenuLine(FALL_OFF_MAP);
							menu.printMenu();
							getline(cin, input);
						}
						break;
					case 100:
						if(team->getLocation()->getRight() != nullptr){
							team->setLocation(team->getLocation()->getRight());
							isValidMove = false;
						}

						else{
							menu.addMenuLine(FALL_OFF_MAP);
							menu.printMenu();
							getline(cin, input);
						}
						break;
				}
			}
			else{
				menu.addMenuLine(WRONG_CHAR);
				menu.printMenu();
				getline(cin, input);
			}
		}	
		else{
			menu.addMenuLine(TOO_LONG);
			menu.printMenu();
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

void Game::clearScreen(){
	for(int n = 0; n < 1000; n++){
		cout << "\n";
	}
}

