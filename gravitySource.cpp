#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "objects.h"
#include "gravitySource.h"
using namespace sf;
using namespace std;


// Main constructor
gravitySource::gravitySource()
{

}

gravitySource::gravitySource(Vector2f _pos,int _mass){

    Vector2f position_grav = _pos;

    // setting mass and velocity to arbitrary values. Velocity of gravity source will always be 0
    mass = _mass;
    velocity.x = 0;
    velocity.y = 0;

    //Setting the shape to be rendered later on
    shape.setPosition(position_grav.x,position_grav.y);
    //shape.setOrigin(position_grav.x-30, position_grav.y-30);
    shape.setFillColor(Color::Cyan);
    shape.setRadius(30);  // can make this dynamic so that the radius changes with options of planet
}

// function returns the mass
int gravitySource::get_mass(){
    return mass;
}

// function sets a new position of the gravity source
void gravitySource::set_position(float p_x, float p_y){
    shape.setPosition(p_x,p_y);
}

// function gets the position of the gravity source
Vector2f gravitySource::get_position(){
    return shape.getPosition();
 }

// function renders the gravity source
void gravitySource::render(sf::RenderWindow* win){
    sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/earth.png");
	shape.setTexture(&shapeTexture);
    win->draw(shape);
 }