 /**************************************************************************************************
** Author: Jose Garay
** Date: 10/19/2018
** Description: Interface file. The Menu class helps add menus to a program. It also helps 
validating user input.
**************************************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP 
#include <string>
#include <vector>
#include <unistd.h>
#include <termios.h>

using std::vector;
using std::string;
class Menu
{
private:
	vector<string> menu;
public:
	Menu();
	~Menu();
	
	bool isInIntegerRange(string);
	bool isNotEmpty(string);
	bool allDigits(string);
	bool isValidNegativeInteger(string);	
	bool isInteger(string);
	bool isDouble(string);
	bool oneDecimalandNumbers(string);
	int checkInputInt(string, int, int);
	int checkInputInt(string, int);
	string checkInputString(string);
	double checkInputDouble(string, double, double);
	char searchForInput(vector<char>);
	int searchForInput(vector<int>);
	int searchForInput(int);

	void addMenuLine(string);
	void printMenu(string);
};
#endif
