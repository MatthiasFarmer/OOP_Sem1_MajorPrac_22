#include "Platform/Platform.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "particle.h"
#include "gravitySource.h"
#include "objects.h"

/*

	MAIN GAME HEADER FILE
	==============
	-initiates window
	-runs main game loop
	-renders
	-updates

*/

class Game : public particle, public gravitySource
{

private:
	//Variables
	particle test;
	gravitySource earth;

	//Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	//Private functions
	void initWindow();
	void initVariables();


public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accesors
	bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();
	void gameLoop(Game game);
	void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow* window, float zoom);
};