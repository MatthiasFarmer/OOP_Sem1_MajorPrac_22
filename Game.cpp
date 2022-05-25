#include "Game.h"

/*

	IMPLEMENTATION OF GAME.H
	========================
	-initiates window
	-runs main game loop
	-renders
	-updates

*/

//------------------------------------------------------------|
//
// PRIVATE FUNCTIONS
//
//------------------------------------------------------------|

void Game::initWindow()
{
	this->videoMode.height = 1200; //set height of window
	this->videoMode.width = 1600;  //set width of window

	this->window = new sf::RenderWindow(this->videoMode, "Graphics Window", sf::Style::Titlebar | sf::Style::Close); //initialising window

	this->window->setFramerateLimit(60); //frame rate cap at 60 fps

}

void Game::initVariables()
{
	this->window = nullptr;     //always good practice to declare variables
	test.create_particles(1000);//creates particles
}
//------------------------------------------------------------|
//
// CONSTRUCTORS & DECONSTRUCTOS
//
//------------------------------------------------------------|

Game::Game()
{
	menuState = 0; //setting default state of menu

	this->initVariables();  //initialises game's variables
	this->initWindow(); 	//initialises window
}

Game::~Game()
{
	delete this->window; 	//to prevent memory leakage
}

//-------------------------------------------------------------|
//
// ACCESSORS
//
//-------------------------------------------------------------|

bool Game::running() const
{
	return this->window->isOpen(); //While window is open, run the game
}

//------------------------------------------------------------|
//
// FUNCTIONS
//
//------------------------------------------------------------|

void Game::pollEvents()
{
	sf::View view(window->getDefaultView());  //sets default view of window
	const float zoomAmount{ 1.1f };           //sets default zoom multiplier


	while(this->window->pollEvent(this->event))//while this window has events(keyboard, mouse, etc)
	{
		switch(this->event.type)			   //Manages the window events from the user
		{
			case sf::Event::Closed:  		   //if the x is clicked, close window
				this->window->close();
				break;

			case sf::Event::KeyPressed: 	   //if esc is clicked, close window
				switch(this->event.key.code){
				case sf::Keyboard::P:
					this->window->close();
				break;

				case sf::Keyboard::S:
					if(menuState != 0){
						menuState--;
					}

				break;

				case sf::Keyboard::W:
					if(menuState != 6){
						menuState++;
					}

				break;

				case sf::Keyboard::H:
					helpScreen();
				break;


				default:
					break;
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
		UPDATES OBJECTS
		-checks events
		-updates particle array relative to earth
	*/

	this->pollEvents();
	applyMenu();
	test.updateParticlesArray(earth);



}

void Game::render()
{
	/*
		RENDER OBJECTS
		-clears window
		-renders particles
		-renders window
		-displays objects on window

	*/

	this->window->clear();

	test.renderParticlesArray(window);
	earth.render(window);

	this->window->display();

}

void Game::gameLoop(Game game)
{
	while(game.running()){
		this->update();
		this->render();
		std::cout << menuState << std::endl;
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


void Game::applyMenu()
{
	switch(menuState){
			case 0:
				test.setParticleAmount(10);
				break;
			case 1:
				test.setParticleAmount(30);
				break;
			case 2:
				test.setParticleAmount(80);
				break;
			case 3:
				test.setParticleAmount(200);
				break;
			case 4:
				test.setParticleAmount(500);
				break;
			case 5:
				test.setParticleAmount(1000);
				break;
			default:
				break;

	}
}

