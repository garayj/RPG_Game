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
}

Game::~Game(){
}



void Game::run(){
	timer = 1;
	won = false;
	//Display start menu and if isRunning is true, runs the game.
	startMenu();
	while(isRunning){
		setup();
		gameplay();
		end();
	}
}

void Game::startMenu(){	
	clearScreen();
	menu.printMenu(MAIN_MENU);
	setIsRunning(menu.checkInputInt(ERROR + MAIN_MENU, 0, 1));	
	clearScreen();
}

void Game::setup(){
	string pause;

	menu.printMenu(WELCOME);

	cout << endl;

	menu.printMenu(PRESS);

	getline(cin,pause);
	clearScreen();

	int selection;
	heroes = new Team(3);

	menu.printMenu(TEAM_CREATION_HEADER);

	//Team selection
	for(int n = 0; n < heroes->getTeamSize(); n++){
		menu.printMenu(CHARACTER_SELECTION_MENU);
		selection  = menu.checkInputInt(ERROR + CHARACTER_SELECTION_MENU, 1, 6);
		heroes->getCharacters()[n] = characterSelection(selection);
		menu.printMenu(CHARACTER_NAME_MENU);
		heroes->getCharacters()[n]->setName(menu.checkInputString(ERROR_CHARACTER_NAME_MENU));
	}

	//Print out team.
	clearScreen();

	menu.printMenu(THIS_IS_YOUR_TEAM);

	heroes->printCharacters();

	menu.printMenu(PRESS);

	getline(cin,pause);

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
	clearScreen();

	//While the game is running, the timer is less than 30 and tthe user has not won, the game will continue.
	//The format of the game is the hero stats are printed to the screen, the map is printed, the heroes move
	//the screen is cleared and an event occurs. If the game is still running after the event, the user is 
	//prompted to continue.
	while(isRunning && timer <= 30 && !won){

		cout << "Day "<< timer << "\n\n";
		heroes->teamStats();
		map.printMap();
		move(heroes);
		clearScreen();
		heroes->teamStats();
		cout << endl;
		event();
		if(isRunning){
			menu.printMenu(CONTINUE);
			setIsRunning(menu.checkInputInt(ERROR + CONTINUE, 0, 1));
		}
		clearScreen();
		timer++;
	}	
	setIsRunning(false);
}

void Game::end(){
	//Then case that the party died during combat.
	if(!heroes->getIsTeamAlive() && !checkTeamHealth()){
		menu.printMenu(DIED);
	}
	//The case that the user has run out of time.
	else if(timer >= 30 && !won){
		menu.printMenu(LOST_TIMER);
	}
	//The case that the user has won!
	else if(timer < 30 && won){
		menu.printMenu(WON);
	}
	delete heroes;
}


void Game::move(Team *team){

	//All needed variables for the method.
	string input;
	int direction;
	bool isValidMove = true;
	vector<char> validDirection = {'w', 'a', 's', 'd'};

	//Print movement options menu.
	menu.printMenu(MOVEMENT_PROMPT);

	char c = menu.searchForInput(validDirection);

	//Checks if the move is a valid move.
	while(isValidMove){
		direction  = c;
		switch(direction){
			case 119:
				if(team->getLocation()->getUp() != nullptr){
					team->setLocation(team->getLocation()->getUp());
					isValidMove = false;
				}
				else{
					menu.printMenu(FALL_OFF_MAP);
					c = menu.searchForInput(validDirection);
				}
				break;
			case 97:
				if(team->getLocation()->getLeft() != nullptr){
					team->setLocation(team->getLocation()->getLeft());
					isValidMove = false;
				}
				else{
					menu.printMenu(FALL_OFF_MAP);
					c = menu.searchForInput(validDirection);
				}
				break;
			case 115:
				if(team->getLocation()->getDown() != nullptr){
					team->setLocation(team->getLocation()->getDown());
					isValidMove = false;
				}
				else{
					menu.printMenu(FALL_OFF_MAP);
					c = menu.searchForInput(validDirection);
				}
				break;
			case 100:
				if(team->getLocation()->getRight() != nullptr){
					team->setLocation(team->getLocation()->getRight());
					isValidMove = false;
				}

				else{
					menu.printMenu(FALL_OFF_MAP);
					c = menu.searchForInput(validDirection);
				}
				break;
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
			spaceEvent = new ForestEvent(heroes, heroes->getLocation());
			delete spaceEvent;
			checkTeam();
			break;
		case CAVE:
			spaceEvent = new CaveEvent(heroes, heroes->getLocation());
			delete spaceEvent;
			checkTeam();
			break;
		case VILLAGE:
			spaceEvent = new VillageEvent(heroes);
			delete spaceEvent;
			checkTeam();
			break;
		case DUNGEON:
			spaceEvent = new DungeonEvent(heroes, heroes->getLocation());
			delete spaceEvent;
			checkTeam();
			fourKeys();
			break;
		case SWAMP:
			spaceEvent = new SwampEvent(heroes, heroes->getLocation());
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

void Game::fourKeys(){
	int counter = 0;
	for(int n = 0; n < heroes->getInventory()->size(); n++){

		if(heroes->getInventory()->at(n)->getItemType() == KEY){
			counter++;
		}
	}
	if(counter == 4){
		setIsRunning(false);
		won = true;
	}

}

bool Game::checkTeamHealth(){
	for(int n = 0; n < heroes->getTeamSize(); n++){
		if(heroes->getCharacters()[n]->getHealth() > 0){
			return true;
		}
	}
	return false;
}

void Game::clearScreen(){
	for(int n = 0; n < 1000; n++){
		cout << "\n";
	}
}
