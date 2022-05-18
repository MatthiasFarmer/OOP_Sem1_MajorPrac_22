#pragma once

class Menu
{

protected:
	//variables
	float rectWidth;
	float rectHeight;
	float rectFlag;
	sf::Vector2f rectSize;

	//Menu objects
	sf::RectangleShape rectOne;
	sf::RectangleShape rectTwo;
	sf::RectangleShape rectThree;

	//Menu selected bools
	bool is_playButtonSelected;
	bool is_playButtonPressed;

public:
	//Constructor / Deconstructor
	Menu();
	virtual ~Menu();

	//Functions
	void initMenu(sf::RenderWindow* win);
	void updateMenuState();
	void renderMenu(sf::RenderWindow* win);

};