#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


//Abstract class for the physical objects
class objects
{
    protected:
        Vector2i position;
        int mass; 
        Vector2i velocity; 
        CircleShape shape; 

    public:
        
        // abstract function get mass
        virtual int get_mass() = 0;

        // abstract fucntion set position
        virtual void set_position() = 0;

};






//Child class for Gravity Source
class gravitySource : public objects
{
    public:
        
        //Default constructor does nothing. Not usefull to have a default constructor
        gravitySource();

        // Main constructor
        gravitySource(Vector2i _pos,int _mass){

            Vector2i position_grav = _pos; 

            // setting mass and velocity to arbitrary values. Velocity of gravity source will always be 0
            mass = _mass; 
            velocity.x = 0;
            velocity.y = 0; 

            //Setting the shape to be rendered later on
            shape.setPosition(position_grav);
            shape.setFillColor(Color::White);
            shape.setRadius(30);  // can make this dynamic so that the radius changes with options of planet
        }

        // function returns the mass
        int get_mass(){
            return mass; 
        }

        // function sets a new position of the gravity source
        void set_position(Vector2i coords){
            shape.setPosition(Vector2i(coords));
        }
};







//Child class for the Particle
class particle : public objects
{
    public:

        //default constructor does nothing, wont be used (always require input)
        particle();

        //main constructor
        particle(int x, int y,  int _mass, Vector2i _velocity){

            // user sets values to change the outcome of simulation

            position.x = x;
            position.y = y;  

            int mass = _mass;
            Vector2i velocity = _velocity; 

            shape.setPosition(Vector2i(position));
            shape.setFillColor(sf::Color::White);
            shape.setRadius(8); // radius can be changed if needed depending on window size

        }

        // function calculates new gravitational force
        void update_physics(gravitySource& source){



        }



};