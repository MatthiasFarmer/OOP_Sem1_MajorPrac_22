#include "Menu.h"
#include <iostream>


//Constructor / Deconstructor===================================
Menu::Menu()
{
	rectWidth = 350.f;
	rectHeight = 75.f;
	rectSize = sf::Vector2f(rectWidth, rectHeight);
	rectFlag = 1.f;

	//setting rects size
	rectOne.setSize(sf::Vector2f(rectSize));
	rectTwo.setSize(sf::Vector2f(rectSize));
	rectThree.setSize(sf::Vector2f(rectSize));

	//setting rects colour
	rectOne.setFillColor(sf::Color::White);
	rectTwo.setFillColor(sf::Color::White);
	rectThree.setFillColor(sf::Color::White);

	//setting rects position
	float heightVariable_1 = (1 * ((600.f/rectHeight) * 6.f));
	float heightVariable_2 = (4 * ((600.f/rectHeight) * 6.f));
	float heightVariable_3 = (7 * ((600.f/rectHeight) * 6.f));
	float newWidth = ((800.f/2.f) - (rectWidth/2.f));

	rectOne.setPosition(sf::Vector2f(newWidth, heightVariable_1));
	rectTwo.setPosition(sf::Vector2f(newWidth, heightVariable_2));
	rectThree.setPosition(sf::Vector2f(newWidth, heightVariable_3));

	is_playButtonPressed = false;
}

Menu::~Menu()
{

}


void Menu::initMenu(sf::RenderWindow*)
{

}
//Functions=====================================================
void Menu::updateMenuState()
{

}

void Menu::renderMenu(sf::RenderWindow* win)
{
	sf::Texture rectOneTexture;
	rectOneTexture.loadFromFile("content/start_FALSE.png");
	rectOne.setTexture(&rectOneTexture);

	sf::Texture rectTwoTexture;
	rectTwoTexture.loadFromFile("content/help_FALSE.png");
	rectTwo.setTexture(&rectTwoTexture);

	sf::Texture rectThreeTexture;
	rectThreeTexture.loadFromFile("content/quit_FALSE.png");
	rectThree.setTexture(&rectThreeTexture);



	win->draw(rectOne);
	win->draw(rectTwo);
	win->draw(rectThree);
}