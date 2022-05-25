#include "Platform/Platform.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "particle.h"
#include "gravitySource.h"
#include "objects.h"
#include "helpscreen.h"

/*

	MAIN GAME HEADER FILE
	==============
	-initiates window
	-runs main game loop
	-renders
	-updates

*/

class Game : public particle, public gravitySource, public helpScreen
{

private:
	//Variables
	particle test;
	gravitySource earth;
	int menuState;


	//Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::Event menuEvent;
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
	void applyMenu();
	void pollEvents();
	void update();
	void render();
	void gameLoop(Game game);
	void zoomViewAt(sf::Vector2i pixel, sf::RenderWindow* window, float zoom);
};