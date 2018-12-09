/**************************************************************************************************
** Author: Jose Garay
** Date: 10/19/2018
** Description: Interface file. The Menu class helps add menus to a program. It also helps 
validating user input.
**************************************************************************************************/
#include "Menu.hpp"
#include <stdexcept>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

/**************************************************************************************************
** Description: Default constructor for the menu class.
**************************************************************************************************/
Menu::Menu(){

}
/**************************************************************************************************
** Description: Default deconstructor for the menu class.
**************************************************************************************************/
Menu::~Menu(){}

/**************************************************************************************************
** Description: Public Method. Check if a string is empty. Takes a string a input and returns a 
boolean. False if empty and true if empty.
**************************************************************************************************/
bool Menu::isNotEmpty(string str){
	if(str == ""){
		return false;
	}
	else{
		return true;
	}
}

/**************************************************************************************************
** Description: Public Method. Checks if a string contains all digits. Takes a string as input and
returns a boolean.
**************************************************************************************************/
bool Menu::allDigits(string str){
	for(int j = 0; j < str.size(); j++){
		if(!isdigit(str[j])){
			return false;
		}
	}
	return true;
}

/**************************************************************************************************
** Description: Public Method. Checks if a string starts with a negative symbol and if it does, 
checks if the rest of the string is digits. Takes a string as input and returns a boolean.
**************************************************************************************************/
bool Menu::isValidNegativeInteger(string str){
	if(str[0] == '-' && str.size() > 1){
		for(int n = 1; n < str.size();n++){
			if(!isdigit(str[n])){
				return false;
			}
		}
	}
	return true;
}

/**************************************************************************************************
** Description: Public Method. Checks to see if a string can be converted to an integer without 
overflowing. Takes a string as input and returns a boolean.
**************************************************************************************************/
bool Menu::isInIntegerRange(string str){
	try{
		stoi(str);
	}
	catch(const std::out_of_range){
		return false;
	}

	return true;
}

/**************************************************************************************************
** Description: Public Method. Adds a string to the menu vector. Takes a string as input and returns
void.
**************************************************************************************************/
void Menu::addMenuLine(string str){
	menu.push_back(str);
}

/**************************************************************************************************
** Description: Public Method. Prints the menu to the console. Takes no arguments and returns void.
**************************************************************************************************/
void Menu::printMenu(){
	for(int n = 0; n < menu.size(); n++){
		cout << menu[n] << endl;
	}
}

/**************************************************************************************************
** Description: Public Method. Clears the string vector. Takes no arguments and returns void.
**************************************************************************************************/
void Menu::clear(){
	menu.clear();
}

/**************************************************************************************************
** Description: Public Method. Checks to see if the string is an integer. Takes a string as input 
and returns a boolean.
**************************************************************************************************/
bool Menu::isInteger(string str){
	if(isNotEmpty(str) && allDigits(str) && isValidNegativeInteger(str) && isInIntegerRange(str) ){
		return true;
	}
	else{
		return false;
	}
}
/**************************************************************************************************
** Description: Public Method. Checks to see if a string as only one decimal and contians only 
numbers in it otherwise. Takes a string as input and returns a boolean.
**************************************************************************************************/
bool Menu::oneDecimalandNumbers(string str){
	int decimalCounter = 0;
	for(int j = 0; j < str.size(); j++){
		if(!isdigit(str[j])){
			if(str[j] == '.'){
				decimalCounter++;	
			}
			else{
				return false;
			}
		}
	}
	if(decimalCounter != 1){
		return false;
	}
	return true;
}

/**************************************************************************************************
** Description: Public Method. Checks to see if a string is a double data type. Takes a string as
input and returns a boolean.
**************************************************************************************************/
bool Menu::isDouble(string str){
	if(isNotEmpty(str) && oneDecimalandNumbers(str)){
		return true;
	}
	else{
		return false;
	}
}
/**************************************************************************************************
** Description: Public Method. Checks to see if string is a string and not an empty line. Takes a
string as input and returns a string. Reprompts user with an error message until the user enters a
string.
**************************************************************************************************/
string Menu::checkInputString(string errorMessage){
	string userInput;
	getline(cin, userInput);
	while(!isNotEmpty(userInput)){
		cout << errorMessage << endl;
		getline(cin, userInput);
	}
	cout << endl;
	return userInput;
}

/**************************************************************************************************
** Description: Public Method. Checks if a user enters a string that can be converted to an integer
data type. Takes a string and two integers as input and returns an integer. Reprompts with user 
with the string and the upper and lower limits can be set.
**************************************************************************************************/
int Menu::checkInputInt(string errorMessage, int lowerLimit, int upperLimit){
	string userInput;
	getline(cin, userInput);
	while(!isInteger(userInput) ||(stoi(userInput) < lowerLimit || stoi(userInput) > upperLimit)){
	
		cout << errorMessage << endl;
		getline(cin, userInput);
	}
	cout << endl;
	return stoi(userInput);
}
/**************************************************************************************************
** Description: Public Method. Checks if a user enters a string that can be converted to an integer
data type. Takes a string and an integer as input and returns an integer. Reprompts with user 
with the string and the lower limits can be set.
**************************************************************************************************/
int Menu::checkInputInt(string errorMessage, int lowerLimit){
	string userInput;
	getline(cin, userInput);
	while(!isInteger(userInput) || stoi(userInput) < lowerLimit){
		cout << errorMessage << endl;
		getline(cin, userInput);
	}
	cout << endl;
	return stoi(userInput);
}

/**************************************************************************************************
** Description: Public Method. Checks if a user enters a string that can be converted to a double 
data type. Takes a string and and two doubles as input and returns a double. Reprompts with user 
with the string and the lower and upper limits can be set.
**************************************************************************************************/
double Menu::checkInputDouble(string errorMessage, double lowerLimit, double upperLimit){
	string userInput;
	getline(cin, userInput);
	while(!isDouble(userInput) || stod(userInput) < lowerLimit || stod(userInput) > upperLimit){
		cout << errorMessage << endl;
		getline(cin, userInput);
	}
	cout << endl;
	return stod(userInput);
}

int Menu::searchForInput(vector<int>key){
	struct termios old_tio, new_tio;
    int c;
    bool flag = true;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    do {
         c = getchar();
         for(int n = 0; n < key.size(); n++){
         	if(c == key[n]){
         		flag = false;
         	}	
         }

    } while(flag);

    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    return c;
}

char Menu::searchForInput(vector<char>key){
	struct termios old_tio, new_tio;
    unsigned char c;
    bool flag = true;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    do {
         c = getchar();
         for(int n = 0; n < key.size(); n++){
         	if(c == key[n]){
         		flag = false;
         	}	
         }

    } while(flag);

    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    return c;
}

int Menu::searchForInput(int arrSize){
	struct termios old_tio, new_tio;
    unsigned char c;
    bool flag = true;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    do {
         c = getchar();
         for(int n = 1; n <= arrSize; n++){
         	if(c == arrSize){
         		flag = false;
         	}	
         }

    } while(flag);

    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    return arrSize - 1;
}
