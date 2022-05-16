#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
using namespace sf;
using namespace std;


//Abstract class for the physical objects
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
        virtual void set_position() = 0;

        // abstract fucntion get position
        virtual Vector2f get_position() = 0; 

};






//Child class for Gravity Source
class gravitySource : public objects
{
    public:
        
        //Default constructor does nothing. Not usefull to have a default constructor
        gravitySource();

        // Main constructor
        gravitySource(Vector2f _pos,int _mass){

            Vector2f position_grav = _pos; 

            // setting mass and velocity to arbitrary values. Velocity of gravity source will always be 0
            mass = _mass; 
            velocity.x = 0;
            velocity.y = 0; 

            //Setting the shape to be rendered later on
            shape.setPosition(position.x,position.y);
            shape.setFillColor(Color::White);
            shape.setRadius(30);  // can make this dynamic so that the radius changes with options of planet
        }

        // function returns the mass
        int get_mass(){
            return mass; 
        }

        // function sets a new position of the gravity source
        void set_position(Vector2f coords){
            shape.setPosition(position.x,position.y);
        }

        // function gets the position of the gravity source
        Vector2f get_position(){
            return shape.getPosition();
        }
};







//Child class for the Particle
class particle : public objects
{
    public:

        //default constructor does nothing, wont be used (always require input)
        particle();

        //main constructor
        particle(float pos_x, float pos_y,  int _mass, float vel_x, float vel_y){

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
        int get_mass(){
            return mass; 
        }

        // function set position
        void set_position(Vector2f coords){
            shape.setPosition(coords.x, coords.y);
        }

        // function get position
        Vector2f get_position(){
            return shape.getPosition();
        }


        // function calculates new gravitational force
        void update_physics(gravitySource& source){

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


            //======== old version ===========
            /*float distance_x = source.get_position().x - position.x;   
            float distance_y = source.get_position().y - position.y;   
            float distance = sqrt(distance_x * distance_x + distance_y * distance_y);  
            float normalized_x = inverse_distance * distance_x;     
            float normalized_y = inverse_distance * distance_y;     
            float inverse_square_dropoff = inverse_distance * inverse_distance;  
            float acceleration_x = normalized_x * s.get_strength() * inverse_square_dropoff;  
            float acceleration_y = normalized_y * s.get_strength() * inverse_square_dropoff;  
            velocity.x += acceleration_x; 
            vel.y += acceleration_y;
            pos.x += vel.x;
            pos.y += vel.y;*/

        }

};