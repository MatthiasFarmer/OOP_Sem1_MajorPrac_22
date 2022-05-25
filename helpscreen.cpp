#include <SFML/Graphics.hpp>
#include "helpscreen.h"
#include <string>

using namespace std;
using namespace sf;

helpScreen::helpScreen(){
    // Loading the font
    Font font; 
    font.loadFromFile("C:\\Users\\jacob\\Downloads\\OOP\\OpenSans-Regular.ttf"); 

    // Initialising the Window
    this->videoMode.height = 800; //set height of window
	this->videoMode.width = 1200;  //set width of window

	this->window = new sf::RenderWindow(this->videoMode, "Help Window", Style::Default); //initialising window

	this->window->setFramerateLimit(60); //frame rate cap at 60 fps

    // Initialising Text
    Text text1;
    text1.setFont(font);
    text1.setString("Help Guide");
    text1.setCharacterSize(40);
    text1.setFillColor(Color::White);
    text1.setPosition(500,0);

    Text text2;
    text2.setFont(font);
    text2.setString("WELCOME TO PARTICLE SIMULATOR");
    text2.setCharacterSize(20);
    text2.setFillColor(Color::White);
    text2.setPosition(430,50);

    Text text3;
    text3.setFont(font);
    text3.setString("Explanation:");
    text3.setCharacterSize(20);
    text3.setFillColor(Color::White);
    text3.setPosition(20,90);

    Text text4;
    text4.setFont(font);
    text4.setString(
        "This is a particle simulator... But what does that mean?\n"
        "Our universe is made up of planets, stars, asteroids, moons, black holes... The list goes on and on!\n"
        "Each of these comsmic bodies follows The Law of Universal Gravitation!!\n"
        "This law basically states that every body of mass in the universe is attracted to every other body of mass.\n"
        "This is why the moon orbits the earth and doesn't just fly away!\n"
        "This program simulates some simple particles, with their own properties such as mass,\n"
        "and dispays the outcome of an interaction between these particles.\n"
        "For example, your particle might have just the right mass and velocity,\n"
        "and start in just the right spot to follow a stable orbit of the gravity source!\n" 
        "Or it might fly straight past or even crash!\n"
        "Its up to you to choose the initial conditions of the particle, and observe the outcome!\n"
        );
    text4.setCharacterSize(18);
    text4.setFillColor(Color::White);
    text4.setPosition(20,150);

    Text text5;
    text5.setFont(font);
    text5.setString("Getting Started:");
    text5.setCharacterSize(20);
    text5.setFillColor(Color::White);
    text5.setPosition(20,450);

    Text text6; 
    text6.setFont(font);
    text6.setString(
        "There is one vital decision for you to make! How many asteroids (particles) will\n"
        "orbit your planet? This decision will allow you to observe a chaotic motion\n"
        "of particles! or simply a serene stable orbit of a few asteroids around a planet\n\n"
        "We hope you enjoy the simulator!"
    );
    text6.setCharacterSize(18);
    text6.setFillColor(Color::White);
    text6.setPosition(20,500);



    // Main Loop for help window
    while (this->window->isOpen()){

        //Checking events

            Event event;
            while (this->window->pollEvent(event)){

                if (event.type == Event::Closed){
                    this->window->close(); 

                    break; 
                }
            }

        // render
        this->window->clear();

        this->window->draw(text1);
        this->window->draw(text2);
        this->window->draw(text3);
        this->window->draw(text4);
        this->window->draw(text5);
        this->window->draw(text6);

        this->window->display(); 

        }

}





