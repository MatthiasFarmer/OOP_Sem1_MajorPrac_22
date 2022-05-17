#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class objects
{
    protected:
        Vector2f position;
        int mass; 
        Vector2f velocity; 
        CircleShape shape; 

    public:
        
        // abstract function get mass
        virtual int get_mass() = 0;

        // abstract function set position
        //virtual void set_position() = 0;

        // abstract fucntion get position
        virtual Vector2f get_position() = 0; 

        virtual void render(RenderWindow& win) = 0; 

};


#endif
