#include "Map.hpp"
#include "Swamp.hpp"
#include "Dungeon.hpp"
#include "Cave.hpp"
#include "Forest.hpp"
#include "Village.hpp"
#include <iostream>
#include "Grass.hpp"
#include "Space.hpp"
#include <stdlib.h>

using std::cout;
using std::endl;

Map::Map(){
	col = 6;
	row = 6;
	board = new Space**[col];
	for(int n = 0; n < row; n++){
		board[n] = new Space*[col];
		for(int p = 0; p < col; p++){
			board[n][p] = nullptr;
		}
	}

	//Players will always start on grass. 
	board[0][0] = new Grass();
	connect(0,0);

	//Randomize the board

	int count = 0;
	int randRow;
	int randCol;

	//4 Dungeons placed on the board randomly.
	while(count < 4){
		randRow = rand() % 6;
		randCol = rand() % 6;
		if(board[randRow][randCol] == nullptr){
			board[randRow][randCol] = new Dungeon();
			connect(randRow,randCol);
			count++;
		}
	}
	count = 0;

	//6 Villages will be placed on the board.
	while(count < 6){
		randRow = rand() % 6;
		randCol = rand() % 6;
		if(board[randRow][randCol] == nullptr){
			board[randRow][randCol] = new Village();
			connect(randRow,randCol);
			count++;
		}
	}
	
	count = 0;

	//6 Swamps will be placed on the board.
	while(count < 6){
		randRow = rand() % 6;
		randCol = rand() % 6;
		if(board[randRow][randCol] == nullptr){
			board[randRow][randCol] = new Swamp();
			connect(randRow,randCol);
			count++;
		}
	}

	count = 0;

	//7 Forests will be placed on the board.
	while(count < 7){
		randRow = rand() % 6;
		randCol = rand() % 6;
		if(board[randRow][randCol] == nullptr){
			board[randRow][randCol] = new Forest();
			connect(randRow,randCol);
			count++;
		}
	}

	count = 0;

	//3 Caves will be placed on the board.
	while(count < 3){
		randRow = rand() % 6;
		randCol = rand() % 6;
		if(board[randRow][randCol] == nullptr){
			board[randRow][randCol] = new Cave();
			connect(randRow,randCol);
			count++;
		}
	}

	//9 other Grasslands will be placed on the board.
	
	for(int n = 0; n < row; n++){
		for(int p = 0; p < col; p++){
			if(board[n][p] == nullptr){
				board[n][p] = new Grass();
				connect(n,p);
			}
		}
	}
}

Map::~Map(){
	for(int n = 0; n < row; n++){
		for(int p = 0; p < col; p++){
			delete board[n][p];
		}
		delete [] board[n];
	}
	delete []board;
}

void Map::printMap(){
	for(int n = 0; n < row; n++){
		cout << "|";
		for(int p = 0; p < col; p++){
			if(getHeroes() != nullptr && getBoard()[n][p] == getHeroes()->getLocation()){
				//Credit: https://stackoverflow.com/questions/35431298/setting-individual-text-colors-in-c
				//I found out how to color text in the terminal. It works on Flip and my own terminal.
				//However I cannot guarentee that it will work anywhere else.
				cout << " \033[5;1;35mX\033[0m ";
			}
			else{
				if(board[n][p]->getSpaceType() == GRASS){
					cout << " \033[1;37mG\033[0m ";
				}
				else if(board[n][p]->getSpaceType() == FOREST){
					cout << " \033[1;32mF\033[0m ";
				}
				else if(board[n][p]->getSpaceType() == VILLAGE){
					cout << " \033[1;33mV\033[0m ";
				}
				else if(board[n][p]->getSpaceType() == DUNGEON){
					cout << " \033[1;31mD\033[0m ";
				}
				else if(board[n][p]->getSpaceType() == SWAMP){
					cout << " \033[1;34mS\033[0m ";
				}
				else if(board[n][p]->getSpaceType() == CAVE){
					cout << " \033[1;30mC\033[0m ";
				}
			}
			cout <<"|";
		}
		cout << endl;
	}
	cout << "\n\n";
	cout << "Legend:" << endl;
	cout << "\033[1;37mG\033[0m: Grassland\n";
	cout << "\033[1;32mF\033[0m: Forest\n";
	cout << "\033[1;33mV\033[0m: Village\n";
	cout << "\033[1;31mD\033[0m: Dungeon\n";
	cout << "\033[1;34mS\033[0m: Swamp\n";
	cout << "\033[1;30mC\033[0m: Cave\n";
	cout << "\n\n";

}

void Map::connect(int n, int p){
	if(n + 1 < row){
		board[n][p]->setDown(board[n+1][p]);	
		if(board[n+1][p] != nullptr){
			board[n+1][p]->setUp(board[n][p]);
		}
	}
	if(n - 1 >= 0){
		board[n][p]->setUp(board[n-1][p]);	
		if(board[n-1][p] != nullptr){
			board[n-1][p]->setDown(board[n][p]);
		}
	}
	if(p + 1 < col){
		board[n][p]->setRight(board[n][p+1]);	
		if(board[n][p+1] != nullptr){
			board[n][p+1]->setLeft(board[n][p]);
		}
	}
	if(p - 1 >= 0){
		board[n][p]->setLeft(board[n][p-1]);	
		if(board[n][p-1] != nullptr){
			board[n][p-1]->setRight(board[n][p]);
		}
	}
}