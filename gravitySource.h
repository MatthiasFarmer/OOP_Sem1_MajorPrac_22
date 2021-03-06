#include <math.h>
#include "objects.h"
using namespace sf;
using namespace std;

#pragma once

//Child class for Gravity Source
class gravitySource : public objects
{
    public:

        //Default constructor does nothing. Not usefull to have a default constructor
        gravitySource();

        // Main constructor
        gravitySource(Vector2f _pos,int _mass);

        // function returns the mass
        int get_mass() override;

        // function sets a new position of the gravity source
        void set_position(float p_x, float p_y);

        // function gets the position of the gravity source
        virtual Vector2f get_position() override;

        // function renders the gravity source
        virtual void render(sf::RenderWindow* win) override;

};

