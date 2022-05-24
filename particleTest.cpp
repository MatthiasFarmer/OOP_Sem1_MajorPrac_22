#include <SFML/Graphics.hpp>
#include <iostream>
#include "particle.h"
#include "gravitySource.h"

using namespace std;
using namespace sf;

// Testing the "Particle" class's constructors and functions

int main(){

    std::cout << "Testing Commenced" << std::flush; 

    // testing default constructor: particle()
    particle A = particle(); 
    if (A.get_position() != Vector2f(300,300)){
        cout << "Error Detected (Default Constructor)" << endl; 
    }


    // testing the defined constructor
    /* also tests:
            get_velocity
            get_position
            get_mass
    */

    // General Values Case 
    // Testing for position, mass and velocity
    particle B = particle(200,100,10,2,-2);
    if (B.get_position() != Vector2f(200,100)){
        cout << "Error Detected (Defined Constructor, Position)" << endl; 
    }
    if (B.get_mass() != 10){
        cout << "Error Detected (Defined Constructor, Mass)" << endl; 
    }
    if (B.get_velocity() != Vector2f(2,-2)){
        cout << "Error Detected (Defined Constructor, Velocity)" << endl;
    }



    // Testing position values: 0's, decimals, large values, negatives
    // Testing for 0's
    {
    particle C = particle(0,0,10,2,-2);
    if (C.get_position() != Vector2f(0,0)){
        cout << "Error Detected (Defined Constructor, Position, 0's)" << endl;
    }
    // Testing for decimals
    particle D = particle(0.1,0.1,10,2,-2);
    if (D.get_position() != Vector2f(0.1,0.1)){
        cout << "Error Detected (Defined Constructor, Position, Decimal)" << endl;
    }
    // Testing for Large Values
    particle E = particle(100000,100000,10,2,-2);
    if (E.get_position() != Vector2f(100000,100000)){
        cout << "Error Detected (Defined Constructor, Position, Large Values)" << endl;
    }
    // Testing for Negatives
    particle F = particle(-10,-10,10,2,-2);
    if (F.get_position() != Vector2f(-10,-10)){
        cout << "Error Detected (Defined Constructor, Position, Large Values)" << endl;
    }
    }



    // Testing Velocity Values: 0's, decimals, large values, negatives
    // Testing for 0's
    {
    particle C = particle(10,10,10,0,0);
    if (C.get_velocity() != Vector2f(0,0)){
        cout << "Error Detected (Defined Constructor, Velocity, 0's)" << endl; 
    }
    // Testing for Decimals
    particle D = particle(10,10,10,0.1,0.1);
    if (D.get_velocity() != Vector2f(0,0)){
        cout << "Error Detected (Defined Constructor, Velocity, Decimals)" << endl; 
    }
    // Testing for large values
    particle E = particle(10,10,10,10000,10000);
    if (E.get_velocity() != Vector2f(10000,10000)){
        cout << "Error Detected (Defined Constructor, Velocity, Large Values)" << endl; 
    }
    // Testing for Negatives
    particle F = particle(10,10,10,-1,-1);
    if (F.get_velocity() != Vector2f(-1,-1)){
        cout << "Error Detected (Defined Constructor, Velocity, Negative)" << endl; 
    }
    }



    // Testing Mass Values: 0's, decimals, large values, negatives
    // Testing for 0's
    {
    particle C = particle(10,10,0,1,1);
    if (C.get_mass() != 10){
        cout << "Error Detected (Defined Constructor, Mass, 0's)" << endl; 
    }
    //Testing for decimals
    particle D = particle(10,10,0.5,1,1);
    if (D.get_mass() != 0.5){
        cout << "Error Detected (Defined Constructor, Mass, Decimals)" << endl; 
    }
    // Testing for large values
    particle E = particle(10,10,100000,1,1);
    if (E.get_mass() != 100000){
        cout << "Error Detected (Defined Constructor, Mass, Large Values)" << endl; 
    }
    // Testing for Negatives
    particle F = particle(10,10,-10,1,1);
    if (F.get_mass() != -10){
        cout << "Error Detected (Defined Constructor, Mass, Negatives)" << endl; 
    }
    }


    // Testing update_Physics function
    // only need to test positive values of mass, and position 
    gravitySource W = gravitySource(Vector2f(600,600),1000);
    particle Z = particle(400,400,10,2,2);
    Z.update_physics(W); 
    if (Z.get_position() != Vector2f(402.088, 402.088)){
        cout << "Error Detected (Update_physics)" << endl; 
    }


    return 0; 
}