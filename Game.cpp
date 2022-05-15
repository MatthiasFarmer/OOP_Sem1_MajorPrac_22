#include "Game.h"

//Private functions =========================================
void Game::initWindow()
{
	this->videoMode.height = 600; //to allow custom heights
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Graphics Window", sf::Style::Titlebar | sf::Style::Close); //initialising window
}

void Game::initVariables()
{
	this->window = nullptr; //always good practice to declare variables
}

//Constructors / deconstructors =========================================
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window; //to prevent memory leakage
}

//Accessors =========================================
bool Game::running() const
{
	return this->window->isOpen();
}

//Functions =========================================
void Game::pollEvents()
{
	while(this->window->pollEvent(this->ev)) //while this window has events(keyboard, mouse, etc)
	{
		switch(this->ev.type) //Manages the window events from the user
		{
			case sf::Event::Closed:  //if the x is clicked, close window
				this->window->close();
				break;
			case sf::Event::KeyPressed: //if esc is clicked, close window
				if(this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
	/*
		- updates particles positions
		- calculates all the math

		Updates the objects within the game.
	*/

	this->pollEvents();

}

void Game::render()
{
	/*
		- clear old frames
		- render objects
		- display frame in window

		Renders game objects.
	*/

	this->window->clear(sf::Color(120, 40, 100, 255)); //RGB alpha, alpha meaning opacity

	//draw game objects

	this->window->display();

}