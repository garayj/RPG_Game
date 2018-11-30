#include "Game.hpp"
#include <ctime>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Game game;
	game.run();
	return 0;
}
