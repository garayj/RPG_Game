/**************************************************************************************************
** Author: Jose Garay
** Date: 11/26/2018
** Description: Implementation for the Map class. The Map class simulates a Map of the entire world 
that this game is set in. Holds spaces of all types and the board is randomized every playthrough. 
Each space is stitched together and the user can have a visual representation of the board printed to 
the screen.
**************************************************************************************************/
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
#include <string>

using std::cout;
using std::endl;
using std::string;

Map::Map(){
	setRow(6);
	setCol(6);
	setBoard(new Space**[getCol()]);

	for(int n = 0; n < getRow(); n++){
		getBoard()[n] = new Space*[getCol()];
		for(int p = 0; p < getCol(); p++){
			getBoard()[n][p] = nullptr;
		}
	}

	//Players will always start on grass. 
	getBoard()[0][0] = new Grass();
	connect(0,0);

	//Randomize the board

	//4 Dungeons are added to the map.
	addSpace(4, DUNGEON);
	//6 Villages are added to the map.
	addSpace(6, VILLAGE);
	//6 Swamps are added to the map.
	addSpace(6, SWAMP);
	//7 Forests are added to the map.
	addSpace(7, FOREST);
	//3 Caves are added to the map.
	addSpace(3, CAVE);


	//9 other Grasslands will be placed on the board.
	
	for(int n = 0; n < getRow(); n++){
		for(int p = 0; p < getCol(); p++){
			if(getBoard()[n][p] == nullptr){
				getBoard()[n][p] = new Grass();
				connect(n,p);
			}
		}
	}
}



void Map::connect(int n, int p){
	//connect the down pointer and the up pointer of the space below the current space.
	if(n + 1 < getRow()){
		getBoard()[n][p]->setDown(getBoard()[n+1][p]);	
		if(getBoard()[n+1][p] != nullptr){
			getBoard()[n+1][p]->setUp(getBoard()[n][p]);
		}
	}
	//connect the up pointer and the down pointer of the space above the current space.
	if(n - 1 >= 0){
		getBoard()[n][p]->setUp(getBoard()[n-1][p]);	
		if(getBoard()[n-1][p] != nullptr){
			getBoard()[n-1][p]->setDown(getBoard()[n][p]);
		}
	}
	//connect the right pointer and the left pointer of the space to the right of the current space.
	if(p + 1 < getCol()){
		getBoard()[n][p]->setRight(getBoard()[n][p+1]);	
		if(getBoard()[n][p+1] != nullptr){
			getBoard()[n][p+1]->setLeft(getBoard()[n][p]);
		}
	}
	//connect the left pointer and the right pointer of the space to the left of the current space.
	if(p - 1 >= 0){
		getBoard()[n][p]->setLeft(getBoard()[n][p-1]);	
		if(getBoard()[n][p-1] != nullptr){
			getBoard()[n][p-1]->setRight(getBoard()[n][p]);
		}
	}
}

void Map::addSpace(int counter, spaceType space){
	int count  = 0;
	int randCol, randRow;	
	while(count < counter){
		randRow = rand() % 6;
		randCol = rand() % 6;
		if(getBoard()[randRow][randCol] == nullptr){
			switch(space){
				case VILLAGE:
					getBoard()[randRow][randCol] = new Village();
					break;
				case CAVE:
					getBoard()[randRow][randCol] = new Cave();
					break;
				case DUNGEON:
					getBoard()[randRow][randCol] = new Dungeon();
					break;
				case FOREST:
					getBoard()[randRow][randCol] = new Forest();
					break;
				case SWAMP:
					getBoard()[randRow][randCol] = new Swamp();
					break;
			}
			connect(randRow,randCol);
			count++;
		}
	}
}

void Map::printMap(){
	string playerSpace = " \033[5;1;35mX\033[0m ";
	string grassSpace = " \033[1;37mG\033[0m ";
	string forestSpace = " \033[1;32mF\033[0m ";
	string villageSpace = " \033[1;33mV\033[0m ";
	string dungeonSpace = " \033[1;31mD\033[0m ";
	string swampSpace = " \033[1;34mS\033[0m ";
	string caveSpace = " \033[1;36mC\033[0m ";
	for(int n = 0; n < getRow(); n++){
		cout << "|";
		for(int p = 0; p < getCol(); p++){
			if(getHeroes() != nullptr && getBoard()[n][p] == getHeroes()->getLocation()){
				//Credit: https://stackoverflow.com/questions/35431298/setting-individual-text-colors-in-c
				//I found out how to color text in the terminal. It works on Flip and my own terminal.
				//However I cannot guarentee that it will work anywhere else.
				cout << playerSpace;
			}
			else{
				if(getBoard()[n][p]->getSpaceType() == GRASS){
					cout << grassSpace;
				}
				else if(getBoard()[n][p]->getSpaceType() == FOREST){
					cout << forestSpace;
				}
				else if(getBoard()[n][p]->getSpaceType() == VILLAGE){
					cout << villageSpace;
				}
				else if(getBoard()[n][p]->getSpaceType() == DUNGEON){
					cout << dungeonSpace;
				}
				else if(getBoard()[n][p]->getSpaceType() == SWAMP){
					cout << swampSpace;
				}
				else if(getBoard()[n][p]->getSpaceType() == CAVE){
					cout << caveSpace;
				}
			}
			cout <<"|";
		}
		cout << endl;
	}
	cout << "\n\n";
	cout << "Legend:" << endl;
	cout << grassSpace << ": Grass\n";
	cout << forestSpace << ": Forest\n";
	cout << villageSpace << ": Village\n";
	cout << dungeonSpace << ": Dungeon\n" ;
	cout << swampSpace << ": Swamp\n" ;
	cout << caveSpace << ": Cave\n";
	cout << "\n\n";

}

Map::~Map(){
	for(int n = 0; n < getRow(); n++){
		for(int p = 0; p < getCol(); p++){
			delete getBoard()[n][p];
		} 
		delete [] getBoard()[n];
	}
	delete []getBoard();
}
