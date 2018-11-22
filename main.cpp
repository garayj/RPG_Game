#include <iostream>
#include <string>
#include "Map.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{

	Map map;
	map.printMap();
	// char move;
	// cout << "Enter wasd" << endl;
	// cin.get(move);
	// cin.ignore();
	// while(move != 'w' && move != 'a' && move != 's' && move != 'd'){
	// 	cout << "Error. Retry" << endl;
	// 	cout << move << endl;
	// 	cin.get(move);
	// 	cin.ignore();
	// }
	// if(move == 'w') {
	// 	cout << "You moved up." << endl;
	// }
	// else if(move == 'a'){
	// 	cout << "You moved left." << endl;
	// }
	// else if(move == 's'){
	// 	cout << "You moved down." << endl;
	// }
	// else if(move == 'd'){
	// 	cout << "You moved right." << endl;
	// }
	// char **array;
	// int size = 4;

	// array = new char*[size];

	// for(int n = 0; n < size; n++){
	// 	array[n] = new char[size];
	// }
	// for(int n = 0; n < size; n++){
	// 	for(int p = 0; p < size; p++){
	// 		array[n][p] == '  ';
	// 	}
	// }
	// for(int n = 0; n < size; n++){
	// 	for(int p = 0; p < size; p++){
	// 		cout << "|" << array[n][p] << "|";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl << endl;

	// for(int n = 0; n < size; n++){
	// 	array[1][n] = '#';
	// }

	// for(int n = 0; n < size; n++){
	// 	for(int p = 0 ;p < size; p++){
	// 		cout << "|" << array[n][p] << "|";
	// 	}
	// 	cout << endl;
	// }


	return 0;
}