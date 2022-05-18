#include "Game.h"

//Private functions ===================================================
void Game::initWindow()
{
	this->videoMode.height = 1200; //to allow custom heights
	this->videoMode.width = 1600;

	this->window = new sf::RenderWindow(this->videoMode, "Graphics Window", sf::Style::Titlebar | sf::Style::Close); //initialising window

	this->window->setFramerateLimit(60); //frame rate cap at 60 fps

}

void Game::initVariables()
{
	this->window = nullptr; //always good practice to declare variables
}


//Constructors / deconstructors ========================================
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window; //to prevent memory leakage
}

//Accessors ============================================================
bool Game::running() const
{
	return this->window->isOpen();
}

//Functions ============================================================
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
				if(this->ev.key.code == (sf::Keyboard::LAlt))
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


	this->window->clear(); //RGB alpha, alpha meaning opacity

	//draw game objects


	//this->renderMenu(window);


	this->window->display();

}

void Game::gameLoop(Game game)
{
	gravitySource earth(Vector2f(1600/2,1200/2), 800);
	particle asteroid1(600,400,10,3,-2);
	particle asteroid2(600,450,10,3,-2);
	particle asteroid3(450,400,10,3,-2);

	int is_play = 0;

	while(is_play != 1){
		std::cout << "Type 1 to start:" << std::endl << "Type 2 for exit:" << std::endl;

		cin >> is_play;

		if(is_play > 2)
		{
			std::cout << "invalid input" << std::endl << std::endl;
		}

		else if(is_play == 2)
		{
			break;
		}
	}



	while (is_play == 1)
	{
		while(game.running()){


		//Updates the game (see implementation for more info)
			this->window->clear();
			game.update();
			asteroid1.update_physics(earth);
			asteroid2.update_physics(earth);
			asteroid3.update_physics(earth);

		//Renders the game (see implementation for more info)
			asteroid1.render(window);
			asteroid2.render(window);
			asteroid3.render(window);
			earth.render(window);
			this->window->display();


		}

	}
}
