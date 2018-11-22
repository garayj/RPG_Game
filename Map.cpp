#include "Map.hpp"
#include <iostream>
#include "Grass.hpp"
#include "Space.hpp"

using std::cout;
using std::endl;

Map::Map(){
	col = 5;
	row = 5;
	board = new Space**[col];
	for(int n = 0; n < row; n++){
		board[n] = new Space*[col];
	}

	for(int n = 0; n < row; n++){
		for(int p = 0; p < col; p++){
			board[n][p] = new Grass();
			if(n + 1 < row){
				board[n][p]->setDown(board[n+1][p]);	
			}
			if(n - 1 >= 0){
				board[n][p]->setUp(board[n-1][p]);	
			}
			if(p + 1 < col){
				board[n][p]->setRight(board[n][p+1]);	
			}
			if(p - 1 >= 0){
				board[n][p]->setLeft(board[n][p-1]);	
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
		for(int p = 0; p < col; p++){
			if(board[n][p]->getType() == GRASS){
				cout << "G";
			}
		}
		cout << endl;
	}

}