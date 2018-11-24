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

using std::streamsize;
using std::numeric_limits;
using std::endl;
using std::cout;
using std::cin;
using std::string;

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
	isRunning(menu.checkInputInt("Enter 1 or 0", 0, 1));	
}

void Game::setup(){
	int selection;
	heroes = new Team();
	cout << "Select your team!" << endl;	
	for(int n = 0; n < heroes->getTeamSize(); n++){
		cout << "What character do you want?" << endl;
		cout << "1."
		selection  = 
		characterSelection()
	}
}


Character* Game::characterSelection(int selection){

}

void Game::gameplay(){
}

void Game::fight(Character *player1, Character *player2){
}

void Game::end(){

}

void Game::displayTeams(){
}

void Game::move(Team *heroes){
	char move;
	cout << "Enter wasd" << endl;
	cin.get(move);
	cin.ignore();

	//Checks to see if user actually inputted a movement character.
	while(move != 'w' && move != 'a' && move != 's' && move != 'd'){
		cout << "Error. Retry" << endl;
		cout << move << endl;
		cin.get(move);
		cin.ignore();
	}

	if(move == 'w') {
		if(team->getLocation()->getUp() != nullptr){
			team->setLocation(team->getLocation()->getUp());
		}
		else{
			cout << "That's off the board or an error" << endl;
		}
	}
	else if(move == 'a'){
		if(team->getLocation()->getLeft() != nullptr){
			team->setLocation(team->getLocation()->getLeft());
		}
		else{
			cout << "That's off the board or an error" << endl;
		}
	}
	else if(move == 's'){
		if(team->getLocation()->getDown() != nullptr){
			team->setLocation(team->getLocation()->getDown());
		}
		else{
			cout << "That's off the board or an error" << endl;
		}
	}
	else if(move == 'd'){
		if(team->getLocation()->getRight() != nullptr){
			team->setLocation(team->getLocation()->getRight());
		}
		else{
			cout << "That's off the board or an error" << endl;
		}
	}
}