#ifndef MAP_HPP
#define MAP_HPP 
#include "Space.hpp"
#include "Team.hpp"
class Map
{
private:
	int row;
	int col;
	Space ***board;
	Team *heroes;
public:
	Space*** getBoard(){return board;};

	void setHeroes(Team *heroes){this->heroes = heroes;};

	Team* getHeroes(){return heroes;};

	Map();
	~Map();
	void printMap();
	void connect(int,int);
	
};
#endif