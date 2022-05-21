#include "Game.h"

/*
	Class that acts as the game engine
	Wraps together all the classes
*/



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
	sf::View view(window->getDefaultView());
	const float zoomAmount{ 1.1f };


	while(this->window->pollEvent(this->event)) //while this window has events(keyboard, mouse, etc)
	{
		switch(this->event.type) //Manages the window events from the user
		{
			case sf::Event::Closed:  //if the x is clicked, close window
				this->window->close();
				break;
			case sf::Event::KeyPressed: //if esc is clicked, close window
				if(this->event.key.code == (sf::Keyboard::LAlt)){
					this->window->close();
				}
				break;
			case sf::Event::MouseWheelScrolled:{
				if (event.mouseWheelScroll.delta > 0)
					zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, (1.f / zoomAmount));
				else if (event.mouseWheelScroll.delta < 0)
					zoomViewAt({ event.mouseWheelScroll.x, event.mouseWheelScroll.y }, window, zoomAmount);
			}
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
	particle test;
	gravitySource earth(Vector2f(900, 500), 2000);
	test.create_particles(1000);

	while(game.running()){

		this->window->clear();
		game.update();

		test.updateParticlesArray(earth);
		test.renderParticlesArray(window);
		earth.render(window);

		this->window->display();


		//Updates the game (see implementation for more info
	}
}

void Game::zoomViewAt(sf::Vector2i pixel, sf::RenderWindow* window, float zoom)
{
	const sf::Vector2f beforeCoord{ window->mapPixelToCoords(pixel) };
	sf::View view{ window->getView() };
	view.zoom(zoom);
	window->setView(view);
	const sf::Vector2f afterCoord{ window->mapPixelToCoords(pixel) };
	const sf::Vector2f offsetCoords{ beforeCoord - afterCoord };
	view.move(offsetCoords);
	window->setView(view);
}
