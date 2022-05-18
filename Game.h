#pragma once

#include "Platform/Platform.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Menu.h"
#include "particle.h"
#include "gravitySource.h"
#include "objects.h"



/*

	Class that acts as the game engine
	Wraps together all the classes

*/

class Game : public Menu, public particle, public gravitySource
{

protected:
	//Variables
	int is_play;


	//Window
	sf::RenderWindow* window;
	sf::Event ev;
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

};

