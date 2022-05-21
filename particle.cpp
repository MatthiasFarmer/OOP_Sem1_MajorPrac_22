#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "particle.h"
#include "objects.h"
#include "gravitySource.h"
#include <random>
using namespace sf;
using namespace std;





//main constructor
particle::particle()
{
    std::uniform_int_distribution<> distr(1600, 700);

    position.x = 300;
    position.y = 300;

    mass = rand() % 20;
    velocity.x = rand() % 2;
    velocity.y = -2;

    shape.setPosition(position.x,position.y);
    shape.setFillColor(Color::White);
    shape.setRadius(2); // radius can be changed if needed depending on window size

}


particle::particle(float pos_x, float pos_y,  int _mass, float vel_x, float vel_y){

// user sets values to change the outcome of simulation

    position.x = pos_x;
    position.y = pos_y;

    mass = _mass;
    velocity.x = vel_x;
    velocity.y = vel_y;

    shape.setPosition(position.x,position.y);
    shape.setFillColor(Color::White);
    shape.setRadius(8); // radius can be changed if needed depending on window size

}

// function returns mass
int particle::get_mass(){
    return mass;
}

// function set position
void particle::set_position(Vector2f coords){
    shape.setPosition(coords.x, coords.y);
}

// function get position
Vector2f particle::get_position(){
    return shape.getPosition();
}

// function calculates new gravitational force
void particle::update_physics(gravitySource& source){

    // find the distances between the source and particle in x and y and puts it in the vector distances
    Vector2f distances = source.get_position() - position;

    // finds the distance between the particle and source using function hypotf from math.h library
    float distance = hypotf(distances.x,distances.y);

    // Calculate inverse distance
    float inverse_distance = 1.f / distance;

    // normalize the vector
    Vector2f normalized_distance = distances * inverse_distance;

    // Find strength of gravity
    float strength_gravity = source.get_mass() * mass * inverse_distance * inverse_distance;

    // calculating the acceleration at a particular instant
    Vector2f acceleration = normalized_distance * strength_gravity;

    //update velocity
    velocity += acceleration;

    //update position
    position += velocity;

}


// function renders the particle
void particle::render(sf::RenderWindow* win){
    shape.setPosition(position.x,position.y);
    win->draw(shape);
}

void particle::initRandomNumber(){   //implementation of random number
    std::random_device rd;
    std::mt19937 randomNumbers(rd());
    srand(time(NULL));                //random number seeding
}

void particle::create_particles(int n){
            number_of_particles = n;

            particlesArray = new particle[number_of_particles];

            particle* particlesArray[1000];

            for(int count = 0 ; count < n ; count++){
                particlesArray[count] = new particle();
            }
            std::cout << particlesArray[number_of_particles];
}

void particle::renderParticlesArray(sf::RenderWindow* win){
            for(int count = 0; count < number_of_particles ; count++){
                particlesArray[count].render(win);
            }
        }

void particle::updateParticlesArray(gravitySource& g){
            for(int count = 0; count < number_of_particles ; count++){
                particlesArray[count].update_physics(g);
            }
        }