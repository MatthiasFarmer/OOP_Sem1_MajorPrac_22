#include "Game.h"

int main()
{
	//Inint game engine
	Game game;

	//Game loop
	while(game.running()){
		//Updates the game (see implementation for more info)
		game.update();

		//Renders the game (see implementation for more info)
		game.render();
	}

	//End of game
	return 0;
}