#ifndef MAP_HPP
#define MAP_HPP 
#include "Space.hpp"
class Map
{
private:
	int row;
	int col;
	Space ***board;
public:
	Map();
	~Map();
	void printMap();
	
};
#endif