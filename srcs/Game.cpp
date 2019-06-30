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
		gameCycle();
		end();
	}
}

void Game::startMenu(){	
	menu.clearScreen();
	menu.printMenu(MAIN_MENU);
	setIsRunning(menu.checkInputInt(ERROR + MAIN_MENU, 0, 1));	
	menu.clearScreen();
}

void Game::setup(){
	string pause;
	menu.printMenu(WELCOME);
	menu.printMenu(PRESS);
	getline(cin,pause);
	menu.clearScreen();
	characterSelectionMenu();	
	//Add the Heroes to the map so the map can know the location of the heroes.
	map.setHeroes(heroes);
	//Set the heroes on the map so they can move around.
	heroes->setLocation(map.getBoard()[0][0]);
}

void Game::characterSelectionMenu(){
	string pause;
	heroes = new Team(3);
	menu.printMenu(TEAM_CREATION_HEADER);
	for(int n = 0; n < heroes->getTeamSize(); n++){
		heroes->getCharacters()[n] = characterSelection();
	}
	//Print out team.
	clearScreen();
	menu.printMenu(THIS_IS_YOUR_TEAM);
	heroes->printCharacters();
	menu.printMenu(PRESS);
	getline(cin,pause);
}


Character* Game::characterSelection(){
	menu.printMenu(CHARACTER_SELECTION_MENU);
	int selection  = menu.checkInputInt(ERROR + CHARACTER_SELECTION_MENU, 1, 6);	
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
	menu.printMenu(CHARACTER_NAME_MENU);
	newCharacter->setName(menu.checkInputString(ERROR_CHARACTER_NAME_MENU));
	return newCharacter;
}

void Game::gameCycle(){
	menu.clearScreen();
	while(isRunning && timer <= 30 && !won){
		play();
	}	
	setIsRunning(false);
}

void Game::play(){
	cout << "Day "<< timer << "\n\n";
	heroes->teamStats();
	map.printMap();
	move(heroes);
	menu.clearScreen();
	heroes->teamStats();
	cout << endl;
	event();
	if(isRunning){
		menu.printMenu(CONTINUE);
		setIsRunning(menu.checkInputInt(ERROR + CONTINUE, 0, 1));
	}
	menu.clearScreen();
	timer++;
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
		team->setLocation(validateDirection(team, direction, validDirection));
		isValidMove = false;
	}
}

Space* Game::validateDirection(Team *team, int direction, vector<char> validDirection){
	bool isNotValidated = true;
	Space* teamMove = team->getLocation();
	while(isNotValidated){
		// Check if the direction is a null pointer.
		switch(direction){
			case 119:
				teamMove = checkSpace(teamMove->getUp());
				break;
			case 97:
				teamMove = checkSpace(teamMove->getLeft());
				break;
			case 115:
				teamMove = checkSpace(teamMove->getDown());
				break;
			case 100:
				teamMove = checkSpace(teamMove->getRight());
				break;
		}
		if(teamMove == nullptr){
			menu.printMenu(FALL_OFF_MAP);
			direction = menu.searchForInput(validDirection);
			teamMove = team->getLocation();
		}
		else{
			return teamMove;
		}
	}
}

Space* Game::checkSpace(Space* space){
	if(space != nullptr){ return space; }
	return nullptr;
}



void Game::event(){
	// Switch between all the different spaces in the game. 
	// Each space has a spaceType which determines which event will occur.
	switch(heroes->getLocation()->getSpaceType()){
		case GRASS:
			spaceEvent = new GrassEvent(heroes);
			break;
		case FOREST:
			spaceEvent = new ForestEvent(heroes, heroes->getLocation());
			break;
		case CAVE:
			spaceEvent = new CaveEvent(heroes, heroes->getLocation());
			break;
		case VILLAGE:
			spaceEvent = new VillageEvent(heroes);
			break;
		case DUNGEON:
			spaceEvent = new DungeonEvent(heroes, heroes->getLocation());
			fourKeys();
			break;
		case SWAMP:
			spaceEvent = new SwampEvent(heroes, heroes->getLocation());
			break;
	}
	delete spaceEvent;
	checkTeam();
}

void Game::checkTeam(){
	if(!heroes->getIsTeamAlive()){
		setIsRunning(false);
	}
}

void Game::fourKeys(){
	// Checks to see if the four keys have been found.
	int counter = 0;
	for(int n = 0; n < heroes->getInventory()->size(); n++){
		if(heroes->getInventory()->at(n)->getItemType() == KEY){ counter++; }
	}
	if(counter == 4){
		setIsRunning(false);
		won = true;
	}

}

bool Game::checkTeamHealth(){
	for(int n = 0; n < heroes->getTeamSize(); n++){
		if(heroes->getCharacters()[n]->getHealth() > 0){ return true; }
	}
	return false;
}


