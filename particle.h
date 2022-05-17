#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "objects.h"
#include "gravitySource.h"
using namespace sf;
using namespace std;

#ifndef PARTICLE_H
#define PARTICLE_H

//Child class for the Particle
//Handles all the physics and position of the particle
class particle : public objects
{
    public:

        //default constructor does nothing, wont be used (always require input)
        particle();

        //main constructor
        particle(float pos_x, float pos_y,  int _mass, float vel_x, float vel_y);

        // function returns mass
        int get_mass() override;

        // function set position
        void set_position(Vector2f coords);

        // function get position
        Vector2f get_position() override;

        // function calculates new gravitational force
        void update_physics(gravitySource& source);


        // function renders the particle
        void render(RenderWindow& win) override;

};

#endif
