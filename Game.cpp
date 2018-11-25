/**************************************************************************************************
** Author: Jose Garay
** Date: 11/2/2018
** Description: Implementation file for the Game Class. The Game Class organizes and conducts all the 
phases of the game.
**************************************************************************************************/
// #include "menuStrings.hpp"
#include "Game.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
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
	cout << "Would you like to play a game?" << endl;
	setIsRunning(menu.checkInputInt("Enter 1 or 0", 0, 1));	
}

void Game::setup(){
	int selection;
	heroes = new Team();

	cout << "Select your team!" << endl;	

	//Team selection
	for(int n = 0; n < heroes->getTeamSize(); n++){
		cout << "What character do you want?" << endl;
		cout << "1. Barbarian" << endl << "2. Vampire\n" << endl;
		selection  = menu.checkInputInt("Select either 1 for Barb or 2 for Vamp", 1, 2);
		heroes->getHeroes()[n] = characterSelection(selection);
	}

	//Print out team.
	cout << "This is your team" << endl;
	for(int n = 0; n < heroes->getTeamSize(); n++){
		cout << n +1 << ". " << heroes->getHeroes()[n]->getType() << endl;
	}
	map.setHeroes(heroes);
	heroes->setLocation(map.getBoard()[0][0]);
}


Character* Game::characterSelection(int selection){
	Character *newCharacter;
	switch(selection){
		case 1:
			newCharacter = new Barbarian();
			break;
		case 2:
			newCharacter = new Vampire();
			break;
	}
	return newCharacter;
}

void Game::gameplay(){
	map.printMap();
	while(isRunning){
		move(heroes);
		map.printMap();
		cout << "Would you like to continue?" << endl;
		setIsRunning(menu.checkInputInt("Enter 1 or 0", 0, 1));	
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

